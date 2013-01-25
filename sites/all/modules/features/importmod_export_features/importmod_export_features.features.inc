<?php
/**
 * @file
 * importmod_export_features.features.inc
 */

/**
 * Implements hook_views_api().
 */
function importmod_export_features_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function importmod_export_features_node_info() {
  $items = array(
    'album' => array(
      'name' => t('album'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
