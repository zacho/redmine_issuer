<?php
// $Id$

/** 
 * @file 
 * Administration page callbacks for the redmine_issuer module.
 */ 


/**
 * Form builder.  Configure Redmine parameters.
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function redmine_issuer_admin_settings() {
  /**
   * What we need here:
   *  - text field for Redmine mailbox  -- e.g. redmine@example.com
   *  - text field for Redmine Project Name(s)  -- machine name, not human name.
   *  - text field for Redmine Issue Type(s)  -- a.k.a. 'Tracker' -- e.g. Bug, Feature, etc.
   *  - text field for Redmine Issue Status(es)  -- e.g. New, Resolved, Closed, etc.
   *  - text field for Redmine Issue Priority(s)  -- e.g. Low, Normal, Urgent, etc.
   */
  $form = array();

  $form['redmine_issuer_mailbox'] = array(
    '#type' => 'textfield',
    '#title' => t('Redmine Mailbox'),
    '#default_value' => variable_get('redmine_issuer_mailbox', null), 
    '#size' => 30,
    '#required' => TRUE,
    '#description' => 'The email address to which new issues will be sent (e.g. redmine@example.com).',
  );

  $form['redmine_issuer_anonymous_address'] = array(
    '#type' => 'textfield',
    '#title' => t('User Address for Anonymous Submissions'),
    '#default_value' => variable_get('redmine_issuer_anonymous_address', null), 
    '#size' => 30,
    '#required' => FALSE,
    '#description' => 'You may allow your DRUPAL users without corresponding REDMINE accounts to submit issues through a general-purpose REDMINE account.  Enter the email address for such an account here.  Don\'t forget to set your Permissions.',
  );

  $form['redmine_issuer_projects'] = array(
    '#type' => 'textfield',
    '#title' => t('Redmine Project Identifier'),
    '#default_value' => variable_get('redmine_issuer_projects', 'fake-project'), 
    '#size' => 50,
    '#required' => TRUE,
    '#description' => 'The project *identifier(s)*, not the project name(s).  E.g. \'fake-project\' not \'Fake Project\'.  Multiple comma-separated values OK.',
  );

  $form['redmine_issuer_trackers'] = array(
    '#type' => 'textfield',
    '#title' => t('Trackers'),
    '#default_value' => variable_get('redmine_issuer_trackers', 'Feature, Bug, Support'), 
    '#size' => 50,
    '#required' => TRUE,
    '#description' => 'The list of possible trackers (issue types) to which users may submit issues.  Multiple, comma-separated values are OK, but bear in mind that the first value in the list will be the default value.',
  );

  $form['redmine_issuer_statuses'] = array(
    '#type' => 'textfield',
    '#title' => t('Statuses'),
    '#default_value' => variable_get('redmine_issuer_statuses', 'New, In Progress, Resolved, Feedback, Closed, Rejected'), 
    '#size' => 50,
    '#required' => TRUE,
    '#description' => 'The list of possible issue statuses to which users may set issues.  Multiple, comma-separated values are OK, but bear in mind that the first value in the list will be the default value.',
  );

  $form['redmine_issuer_priorities'] = array(
    '#type' => 'textfield',
    '#title' => t('Priorities'),
    '#default_value' => variable_get('redmine_issuer_priorities', 'Normal, Low, High, Urgent, Immediate'), 
    '#size' => 50,
    '#required' => TRUE,
    '#description' => 'The list of possible priorities to which users may set issues.  Multiple, comma-separated values are OK, but bear in mind that the first value in the list will be the default value.  The default list here reflects the default list on a new Redmine install, but you may want to restrict users to only submitting "Normal" priority tasks, for example.',
  );

  $form['redmine_issuer_categories'] = array(
    '#type' => 'textfield',
    '#title' => t('Categories'),
    '#default_value' => variable_get('redmine_issuer_categories', NULL),
    '#size' => 50,
    '#required' => FALSE,
    '#description' => 'The list of possible categories.  Multiple comma-separated values are OK, or this may be left blank.  Redmine project categories may be used to auto-assign issues to a given Redmine user. ',
  );

  return system_settings_form($form);

}


?>
