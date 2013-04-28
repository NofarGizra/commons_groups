<?php
/**
 * @file
 * commons_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commons_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commons_groups_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function commons_groups_image_default_styles() {
  $styles = array();

  // Exported image style: 35x35.
  $styles['35x35'] = array(
    'name' => '35x35',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '35',
          'height' => '35',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: 50x50.
  $styles['50x50'] = array(
    'name' => '50x50',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '50',
          'height' => '50',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function commons_groups_default_message_type() {
  $items = array();
  $items['trusted_contact_request_approved'] = entity_import('message_type', '{
    "name" : "trusted_contact_request_approved",
    "description" : "Trusted-Contact request approved",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003E[message:field-\\u003C\\/span\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003Eapproving\\u003C\\/span\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003E-user:field-name-first]\\u0026nbsp;[message:field-approving-user:field-name-last] approved your Trusted-Contact request.\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003E[message:field-\\u003C\\/span\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003Eapproving\\u003C\\/span\\u003E\\u003Cspan style=\\u0022font-size: 13px;\\u0022\\u003E-user:field-name-first]\\u0026nbsp;[message:field-approving-user:field-name-last] approved your Trusted-Contact request.\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EView their profile.. etc.\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EView their profile.. etc.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['trusted_contact_request_pending'] = entity_import('message_type', '{
    "name" : "trusted_contact_request_pending",
    "description" : "Trusted-Contact request pending",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003EYou have a Trusted-Contact request pending from [message:field-requesting-user:field-name-first] [message:field-requesting-user:field-name-last]\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou have a Trusted-Contact request pending from [message:field-requesting-user:field-name-first] [message:field-requesting-user:field-name-last]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EHello,\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou may approve\\u0026nbsp;or ignore.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E@{approve-url} | \\u003Cspan\\u003E@{ignore-url}\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EHello,\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003EYou may approve\\u0026nbsp;or ignore.\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003E@{approve-url} | \\u003Cspan\\u003E@{ignore-url}\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function commons_groups_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('Use groups to contain people and content related by a shared interest or purpose.'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
  );
  return $items;
}
