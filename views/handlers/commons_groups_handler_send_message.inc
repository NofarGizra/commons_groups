<?php

class commons_groups_handler_send_message extends views_handler_field {

  function render($values) {
    return l(t('Send private message'), 'messages/new/' . $values->og_membership_etid);
  }
}
