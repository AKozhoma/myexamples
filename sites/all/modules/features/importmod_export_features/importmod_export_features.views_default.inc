<?php
/**
 * @file
 * importmod_export_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function importmod_export_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'album';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'album';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Albums';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'node';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No album with such parameters!

Change your filter\'s criterion please. ';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Music substyle (field_album_substyle) */
  $handler->display->display_options['relationships']['field_album_substyle_tid']['id'] = 'field_album_substyle_tid';
  $handler->display->display_options['relationships']['field_album_substyle_tid']['table'] = 'field_data_field_album_substyle';
  $handler->display->display_options['relationships']['field_album_substyle_tid']['field'] = 'field_album_substyle_tid';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'musicsubstyle' => 'musicsubstyle',
    'musicstyle' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Label */
  $handler->display->display_options['fields']['field_label']['id'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['table'] = 'field_data_field_label';
  $handler->display->display_options['fields']['field_label']['field'] = 'field_label';
  $handler->display->display_options['fields']['field_label']['type'] = 'text_plain';
  /* Field: Content: Singer */
  $handler->display->display_options['fields']['field_singer']['id'] = 'field_singer';
  $handler->display->display_options['fields']['field_singer']['table'] = 'field_data_field_singer';
  $handler->display->display_options['fields']['field_singer']['field'] = 'field_singer';
  $handler->display->display_options['fields']['field_singer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_singer']['type'] = 'text_plain';
  /* Field: Content: Year */
  $handler->display->display_options['fields']['field_year']['id'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['table'] = 'field_data_field_year';
  $handler->display->display_options['fields']['field_year']['field'] = 'field_year';
  $handler->display->display_options['fields']['field_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_year']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: List of songs */
  $handler->display->display_options['fields']['field_song']['id'] = 'field_song';
  $handler->display->display_options['fields']['field_song']['table'] = 'field_data_field_song';
  $handler->display->display_options['fields']['field_song']['field'] = 'field_song';
  $handler->display->display_options['fields']['field_song']['label'] = 'Songs';
  $handler->display->display_options['fields']['field_song']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_song']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_song']['delta_offset'] = '0';
  /* Field: Content: Music style */
  $handler->display->display_options['fields']['field_album_style']['id'] = 'field_album_style';
  $handler->display->display_options['fields']['field_album_style']['table'] = 'field_data_field_album_style';
  $handler->display->display_options['fields']['field_album_style']['field'] = 'field_album_style';
  $handler->display->display_options['fields']['field_album_style']['element_label_colon'] = FALSE;
  /* Field: Content: Music substyle */
  $handler->display->display_options['fields']['field_album_substyle']['id'] = 'field_album_substyle';
  $handler->display->display_options['fields']['field_album_substyle']['table'] = 'field_data_field_album_substyle';
  $handler->display->display_options['fields']['field_album_substyle']['field'] = 'field_album_substyle';
  $handler->display->display_options['fields']['field_album_substyle']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'album' => 'album',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Music style (field_album_style) */
  $handler->display->display_options['filters']['field_album_style_tid']['id'] = 'field_album_style_tid';
  $handler->display->display_options['filters']['field_album_style_tid']['table'] = 'field_data_field_album_style';
  $handler->display->display_options['filters']['field_album_style_tid']['field'] = 'field_album_style_tid';
  $handler->display->display_options['filters']['field_album_style_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_album_style_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_album_style_tid']['expose']['operator_id'] = 'field_album_style_tid_op';
  $handler->display->display_options['filters']['field_album_style_tid']['expose']['label'] = 'Music style';
  $handler->display->display_options['filters']['field_album_style_tid']['expose']['operator'] = 'field_album_style_tid_op';
  $handler->display->display_options['filters']['field_album_style_tid']['expose']['identifier'] = 'field_album_style_tid';
  $handler->display->display_options['filters']['field_album_style_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_album_style_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_album_style_tid']['vocabulary'] = 'musicstyle';
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_album_substyle_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Music sybstyle';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'musicsubstyle';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name album';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'album';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Albums';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['album'] = $view;

  $view = new view();
  $view->name = 'usersview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'UsersView';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_name_user' => 'field_name_user',
    'field_lastname_user' => 'field_lastname_user',
    'field_datebirth_user' => 'field_datebirth_user',
    'mail' => 'mail',
    'field_music_user' => 'field_music_user',
    'field_submusic_user' => 'field_submusic_user',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_name_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lastname_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_datebirth_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_music_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_submusic_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No users with such parameters!

Change filter settings please.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: User: User&#039;s submusic (field_submusic_user) */
  $handler->display->display_options['relationships']['field_submusic_user_tid']['id'] = 'field_submusic_user_tid';
  $handler->display->display_options['relationships']['field_submusic_user_tid']['table'] = 'field_data_field_submusic_user';
  $handler->display->display_options['relationships']['field_submusic_user_tid']['field'] = 'field_submusic_user_tid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login:';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: User name */
  $handler->display->display_options['fields']['field_name_user']['id'] = 'field_name_user';
  $handler->display->display_options['fields']['field_name_user']['table'] = 'field_data_field_name_user';
  $handler->display->display_options['fields']['field_name_user']['field'] = 'field_name_user';
  $handler->display->display_options['fields']['field_name_user']['label'] = 'Name:';
  $handler->display->display_options['fields']['field_name_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_user']['type'] = 'text_plain';
  /* Field: User: User lastname */
  $handler->display->display_options['fields']['field_lastname_user']['id'] = 'field_lastname_user';
  $handler->display->display_options['fields']['field_lastname_user']['table'] = 'field_data_field_lastname_user';
  $handler->display->display_options['fields']['field_lastname_user']['field'] = 'field_lastname_user';
  $handler->display->display_options['fields']['field_lastname_user']['label'] = 'Lastname:';
  $handler->display->display_options['fields']['field_lastname_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lastname_user']['type'] = 'text_plain';
  /* Field: User: Date of birth */
  $handler->display->display_options['fields']['field_datebirth_user']['id'] = 'field_datebirth_user';
  $handler->display->display_options['fields']['field_datebirth_user']['table'] = 'field_data_field_datebirth_user';
  $handler->display->display_options['fields']['field_datebirth_user']['field'] = 'field_datebirth_user';
  $handler->display->display_options['fields']['field_datebirth_user']['label'] = 'Date of birth:';
  $handler->display->display_options['fields']['field_datebirth_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datebirth_user']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'E-mail:';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: User's music */
  $handler->display->display_options['fields']['field_music_user']['id'] = 'field_music_user';
  $handler->display->display_options['fields']['field_music_user']['table'] = 'field_data_field_music_user';
  $handler->display->display_options['fields']['field_music_user']['field'] = 'field_music_user';
  $handler->display->display_options['fields']['field_music_user']['label'] = 'User\'s music:';
  $handler->display->display_options['fields']['field_music_user']['element_label_colon'] = FALSE;
  /* Field: User: User's submusic */
  $handler->display->display_options['fields']['field_submusic_user']['id'] = 'field_submusic_user';
  $handler->display->display_options['fields']['field_submusic_user']['table'] = 'field_data_field_submusic_user';
  $handler->display->display_options['fields']['field_submusic_user']['field'] = 'field_submusic_user';
  $handler->display->display_options['fields']['field_submusic_user']['label'] = 'User\'s submusic:';
  $handler->display->display_options['fields']['field_submusic_user']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Created date';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: User&#039;s music (field_music_user) */
  $handler->display->display_options['filters']['field_music_user_tid']['id'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['table'] = 'field_data_field_music_user';
  $handler->display->display_options['filters']['field_music_user_tid']['field'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_music_user_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['operator_id'] = 'field_music_user_tid_op';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['label'] = 'Music style';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['operator'] = 'field_music_user_tid_op';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['identifier'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_music_user_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_music_user_tid']['vocabulary'] = 'musicstyle';
  $handler->display->display_options['filters']['field_music_user_tid']['hierarchy'] = 1;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_submusic_user_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Music substyle';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'musicsubstyle';
  /* Filter criterion: User: User name (field_name_user) */
  $handler->display->display_options['filters']['field_name_user_value']['id'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['table'] = 'field_data_field_name_user';
  $handler->display->display_options['filters']['field_name_user_value']['field'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_name_user_value']['group'] = 1;
  $handler->display->display_options['filters']['field_name_user_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name_user_value']['expose']['operator_id'] = 'field_name_user_value_op';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['label'] = 'User name';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['operator'] = 'field_name_user_value_op';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['identifier'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: User&#039;s submusic (field_submusic_user) */
  $handler->display->display_options['relationships']['field_submusic_user_tid']['id'] = 'field_submusic_user_tid';
  $handler->display->display_options['relationships']['field_submusic_user_tid']['table'] = 'field_data_field_submusic_user';
  $handler->display->display_options['relationships']['field_submusic_user_tid']['field'] = 'field_submusic_user_tid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: User&#039;s music (field_music_user) */
  $handler->display->display_options['filters']['field_music_user_tid']['id'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['table'] = 'field_data_field_music_user';
  $handler->display->display_options['filters']['field_music_user_tid']['field'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_music_user_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['operator_id'] = 'field_music_user_tid_op';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['label'] = 'Music style';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['operator'] = 'field_music_user_tid_op';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['identifier'] = 'field_music_user_tid';
  $handler->display->display_options['filters']['field_music_user_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_music_user_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_music_user_tid']['vocabulary'] = 'musicstyle';
  $handler->display->display_options['filters']['field_music_user_tid']['hierarchy'] = 1;
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'field_submusic_user_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Music substyle';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'musicsubstyle';
  /* Filter criterion: User: User name (field_name_user) */
  $handler->display->display_options['filters']['field_name_user_value']['id'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['table'] = 'field_data_field_name_user';
  $handler->display->display_options['filters']['field_name_user_value']['field'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_name_user_value']['group'] = 1;
  $handler->display->display_options['filters']['field_name_user_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_name_user_value']['expose']['operator_id'] = 'field_name_user_value_op';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['label'] = 'User name';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['operator'] = 'field_name_user_value_op';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['identifier'] = 'field_name_user_value';
  $handler->display->display_options['filters']['field_name_user_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = 'root';
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = '!=';
  $handler->display->display_options['filters']['name']['value'] = 'root';
  $handler->display->display_options['path'] = 'users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['usersview'] = $view;

  return $export;
}
