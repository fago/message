<?php
// $Id:$

$plugin = array(
  'name' => 'message_ctools_export_ui',
  'schema' => 'message',
  'menu' => array(
    'menu item' => 'message',
  ),
  'title' => t('Message'),
  'handler' => array(
    'class' => 'message_ctools_export_ui',
    // The parent is the plugin name, not the class name.
    'parent' => 'ctools_export_ui',
  ),
);