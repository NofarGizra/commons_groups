<?php
/**
 * @file
 * commons_groups_directory.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commons_groups_directory_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}