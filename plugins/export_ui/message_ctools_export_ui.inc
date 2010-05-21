<?php
// $Id:$

$plugin = array(
  'name' => 'message_ctools_export_ui',
  'menu item' => 'message',
  'title' => t('Message'),
  'handler' => array(
    'class' => 'message_ctools_export_ui',
    // The parent is the plugin name, not the class name, but in our case it is
    // the same.
    'parent' => 'ctools_export_ui',
  ),
);