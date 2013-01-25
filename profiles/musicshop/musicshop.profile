<?php
/**
 * @file
 * Enables modules and site configuration for a Music shop site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function musicshop_form_install_configure_form_alter (&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'Music Shop';
}

/**
 * Implements hook_install_tasks ().
 */
function musicshop_install_tasks () {
  $tasks = array(
    'musicshop_import_settings' => array(
      'display_name' => st ('Import settings'),
    ),
    'musicshop_import_content' => array(
      'display_name' => st ('Import content'),
      'display' => TRUE,
    ),
  );
  return $tasks;
}

function musicshop_import_settings (&$install_state) {
  $theme = array (
    'theme_default' => 'albummusic',
    'admin_theme' => 'seven',
  );
  theme_enable ($theme);
  foreach ($theme as $var => $theme) {
    if ( !is_numeric ($var)) {
      variable_set ($var, $theme);
    }
  }
  // Disable the default Bartik theme
  theme_disable(array('bartik'));
}

/**
 * Import information about music album
 */
function musicshop_import_content () {
  $path = drupal_get_path ('module', 'importmod');
  $file = file ($path.'/files/album.csv');
  if (!$file) {
    return drupal_set_message ('File album.csv does not exists');
  }
  else {
    unset ($file[0]);
    $count = count ($file);
    // Create new Vocabulary with music style
    $vid = musicshop_vocabulary ('Music style', 'musicstyle');
    $vid2 = musicshop_vocabulary ('Music substyle', 'musicsubstyle');
    // Delete all old node and terms
    musicshop_delete_node_users_and_term ();

    for ($i = 1; $i <= $count; $i++) {
      $data_node = explode (',', $file[$i]);
      // Create styles music at Vocabular Music style
      $exist_term = db_query ("SELECT tid FROM {taxonomy_term_data} WHERE name = :name", array(':name' => $data_node[5]))->fetchField();
      if (!$exist_term) {
        musicshop_taxonomy_save_term ($data_node[5], $vid, 0);
      }
      // Create substyles music and theirs connection to the style of music at Vocabular Music style
      $exist_substyle = db_query ("SELECT tid FROM {taxonomy_term_data} WHERE name = :name", array(':name' => trim ($data_node[6])))->fetchField();
      if (!$exist_substyle) {
        taxonomy_save_term (trim ($data_node[6]), $vid2, 0);
      }
    }
    musicshop_import_users ();
  }

  return;
}

/**
 * Import information about users
 */
function musicshop_import_users () {

  $path = drupal_get_path ('module', 'importmod');
  $file = file ($path.'/files/user.csv');
  if (!$file) {
    return drupal_set_message ('File user.csv does not exists');
  }
  else {
    $data_user = array();
    unset ($file[0]);
    $count = count ($file);

    for ($i = 1; $i <= $count; $i++) {
      $data_user = explode (',', $file[$i]);
      $exists = db_query ("SELECT uid FROM {users} WHERE name = :name", array(':name' => $data_user[0]))->fetchField();
      if (!$exists) {
        $user = new stdClass();
        // Create custom fields for User node
        $user->field_name_user['und'][0]['value']  = check_plain ($data_user[1]);
        $user->field_lastname_user['und'][0]['value']  = check_plain ($data_user[2]);
        $user->name = check_plain ($data_user[0]);
        $user->signature = check_plain ($data_user[0]);
        $user->mail  = check_plain ($data_user[4]);
        $user->init  = check_plain ($data_user[4]);
        $user->field_datebirth_user['und'][0]['value']  = $data_user[3];
        $user->pass = mt_rand (1000, 9999);
        // Find needed termins for link from Vocabulary
        $term['style'] = taxonomy_get_term_by_name ($data_user[5], 'musicstyle');
        $term['substyle'] = taxonomy_get_term_by_name (trim ($data_user[6]), 'musicsubstyle');
        // Create Usernode's field with link to Sub-Music style at Vocabulary
        foreach ($term['substyle'] as $substyle) {
          $user->field_submusic_user['und'][]['tid'] = $substyle->tid;
        }
        // Create Usernode's field with link to Music style at Vocabulary
        foreach ($term['style'] as $style) {
          $user->field_music_user['und'][]['tid'] = $style->tid;
        }
        // Saving information about User
        user_save ($user);
      }
    }
    musicshop_import_albums ();
  }
}

/**
 * Create album as our nodes
 */
function musicshop_import_albums () {
  $path = drupal_get_path ('module', 'importmod');
  $file = file ($path.'/files/album.csv');
  if (!$file) {
    return drupal_set_message ('File album.csv does not exists');
  }
  else {
    sort ($file);
    unset ($file[0]);
    $count = count ($file);
    for ($i = 1; $i <= $count; $i++) {
      $data_node = explode (',', $file[$i]);
      //new_type_node('album', 'Music album');
      $exists = db_query ("SELECT nid FROM {node} WHERE type = 'album' AND title = :title", array(':title' => $data_node[0]))->fetchField();
      if (!$exists) {
        $node = new stdClass ();
        $node->type ='album';
        node_object_prepare ($node);
        // Create custom fields for Album node
        $node->title = $data_node[0];
        $node->field_song['und'][0]['value'] = ucfirst (strtolower (check_plain ($data_node[1])));
        $node->field_label['und'][0]['value'] = check_plain ($data_node[2]);
        $node->field_year['und'][0]['value'] = check_plain ($data_node[3]);
        $node->field_singer['und'][0]['value'] =check_plain ($data_node[4]);
        // Find needed termins for link from Vocabulary
        $term['style'] = taxonomy_get_term_by_name ($data_node[5], 'musicstyle');
        $term['substyle'] = taxonomy_get_term_by_name (trim ($data_node[6]), 'musicsubstyle');
        // Create Albumnode's field with link to Sub-Music style at Vocabulary
        foreach ($term['substyle'] as $substyle) {
          $node->field_album_substyle['und'][]['tid'] = $substyle->tid;
        }
        // Create Albumnode's field with link to Music style at Vocabulary
        foreach ($term['style'] as $style) {
          $node->field_album_style['und'][]['tid'] = $style->tid;
        }
      }
      else {
        $node->field_song['und'][0]['value'] .= ",\n".ucfirst (strtolower ($data_node[1]));
      }
      // Saving information about User
      node_submit ($node);
      node_save ($node);
    }

    return;
  }
}

/**
 * Create a new vocabulary
 */
function  musicshop_vocabulary ($name, $mname) {
  $vid = db_query ("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = :mname", array(':mname' => $mname))->fetchField(); 
  if ($vid > 0) {
    return $vid;
  }
  else {
    $vocabulary = new stdClass();
    $vocabulary->name = $name;
    $vocabulary->machine_name = $mname;
    $vocabulary->hierarchy = 1;
    taxonomy_vocabulary_save ($vocabulary);
    return db_query ("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = :mname", array(':mname' => $mname))->fetchField(); 
  }
}

/**
 * Add terms to our vocabulary
 */
function musicshop_taxonomy_save_term ($name, $vid, $parent = 0) {
  $tid = db_query ("SELECT tid FROM {taxonomy_term_data} WHERE name = :name AND vid = :vid", array(':name' => $name, ':vid' => $vid))->fetchField();
  if ($tid > 0) {
    return $tid;
  }
  else {
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $vid;
    if (isset($parent)) {
      $term->parent = $parent;
    }
    taxonomy_term_save ($term);
  return $term->vid;
  }
}

/**
 * Delete nodes and taxonomy terms
 */
function musicshop_delete_node_users_and_term () {
  $all_nodes = db_query ("SELECT nid FROM {node} WHERE type = 'user' or  type = 'album'");
  while ($nid = $all_nodes->fetchColumn(0)) {
    node_delete ($nid);
  }
  $vid = db_query ("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'musicstyle'")->fetchField();
  $vid2 = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = 'musicsubstyle'")->fetchField();
  $all_terms = db_query ("SELECT tid FROM {taxonomy_term_data} WHERE vid = :vid OR vid = :vid2", array(':vid' => $vid, ':vid2' => $vid2));
  while ($tid = $all_terms->fetchColumn(0)) {
    taxonomy_term_delete ($tid);
  }
  db_query ("DELETE FROM {users} WHERE uid > 1")->execute ();
  db_query ("DELETE FROM {taxonomy_index}")->execute ();
  return;
}