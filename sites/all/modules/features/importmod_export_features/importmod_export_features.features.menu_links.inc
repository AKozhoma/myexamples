<?php
/**
 * @file
 * importmod_export_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function importmod_export_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:album
  $menu_links['main-menu:album'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'album',
    'router_path' => 'album',
    'link_title' => 'Albums',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: main-menu:users
  $menu_links['main-menu:users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'users',
    'router_path' => 'users',
    'link_title' => 'Users',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/album
  $menu_links['navigation:node/add/album'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/album',
    'router_path' => 'node/add/album',
    'link_title' => 'album',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Albums');
  t('Home');
  t('Users');
  t('album');


  return $menu_links;
}
