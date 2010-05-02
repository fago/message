<?php
// $Id:$

/**
 * Base class for export UI.
 */
class message_plugin_export_ui extends export_ui_plugin {

  /**
   * Information about options for all kinds of purposes will be held here.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['description'] = array('default' => '');
    $options['message'] = array('default' => '');
    return $options;
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_form(&$form, &$form_state, $op, $export) {
    parent::options_form($form, $form_state, $op, $export);
    $form['info']['description'] = array(
      '#title' => t('Description'),
      '#type' => 'textfield',
      '#default_value' => $this->options['description'],
      '#description' => t('The message description.'),
    );

    $form['message'] = array(
      '#title' => t('Message'),
      '#type' => 'textfield',
      '#default_value' => $this->options['message'],
      '#description' => t('The message'),
      '#required' => TRUE,
    );
  }


  /**
   * Load a single exportable.
   *
   * Derived class must implement this.
   *
   * @param $id
   *   The unique ID of the exportable.
   */
  function load($id, $reset = FALSE) {
   return message_load($id, $reset);
  }

  /**
   * Save an exportable.
   *
   * Derived class must implement this.
   *
   * @param $export
   *   The exportale object.
   */
  function save($export) {
    return message_save($export);
  }

  /**
   * Delete an exportable.
   *
   * Derived class must implement this.
   *
   * @param $export
   *   The exportale object.
   */
  function delete($export) {
    return message_delete($export);
  }
}
