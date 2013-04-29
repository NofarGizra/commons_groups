<?php
/**
 * @file
 * Action to set the state of a user in a group.
 */

function commons_groups_set_state_active_action_info() {
  return array('commons_groups_set_state_active' => array(
    'type' => 'og_membership',
    'label' => t('Set Membership state to Active'),
    'configurable' => FALSE,
  ));
}

//function commons_groups_set_state_action_form($context) {
//  $form['state'] = array(
//    '#type' => 'select',
//    '#title' => t('State'),
//    '#description' => t('Choose the state to set for the selected users in the group.'),
//    '#options' => og_group_content_states(),
//    '#default_value' => OG_STATE_ACTIVE,
//    '#required' => TRUE,
//  );
//  return $form;
//}
//
//function commons_groups_set_state_action_submit($form, $form_state) {
//  return array('state' => $form_state['values']['state']);
//}

function commons_groups_set_state_active_action($og_membership) {
  if ($og_membership->state == OG_STATE_ACTIVE) {
    return;
  }

  // Don't process the group manager, if exists.
  $group = entity_load_single($og_membership->group_type, $og_membership->gid);
  if (!empty($group->uid) && $group->uid == $og_membership->etid && $og_membership->entity_type == 'user') {
    return;
  }

  $og_membership->state = OG_STATE_ACTIVE;
  $og_membership->save();
}

