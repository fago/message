<?php

/**
 * Implementation of hook_views_default_views().
 */
function message_flag_example_views_default_views() {
  $views = array();

  // Exported view: message_flag_example
  $view = new view;
  $view->name = 'message_flag_example';
  $view->description = 'Show the activity of the users being followed by the current user.';
  $view->tag = 'message_flag_example';
  $view->view_php = '';
  $view->base_table = 'message_instance';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'iid' => array(
      'label' => 'Message realm',
      'required' => 0,
      'id' => 'iid',
      'table' => 'message_instance',
      'field' => 'iid',
      'relationship' => 'none',
    ),
    'uid' => array(
      'label' => 'Message user',
      'required' => 0,
      'id' => 'uid',
      'table' => 'message_instance',
      'field' => 'uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'name' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'uid',
    ),
    'render' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'skip_access' => 1,
      'exclude' => 0,
      'id' => 'render',
      'table' => 'message_instance',
      'field' => 'render',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'message_realm_flag' => array(
      'operator' => 'in',
      'value' => array(
        'message_flag_example_user' => 'message_flag_example_user',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'message_realm_flag',
      'table' => 'message_realm',
      'field' => 'message_realm_flag',
      'relationship' => 'iid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('empty', 'You don\'t follow anyone, or they still didn\'t do anything interesting.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('row_options', array(
    'inline' => array(
      'name' => 'name',
      'render' => 'render',
    ),
    'separator' => '',
    'hide_empty' => 0,
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'message-flag-example');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Message flag example',
    'description' => 'Show the activity of users I follow.',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}