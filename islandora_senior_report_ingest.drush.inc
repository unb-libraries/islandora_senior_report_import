<?php

/**
 * @file
 * Drush commands : ingest senior report objects from dspace in Fedora.
 */

require_once 'inc/DspaceSimpleArchiveExport.php';
require_once 'inc/IslandoraSeniorReport.php';
require_once 'lib/smarty/distribution/libs/Smarty.class.php';

/**
 * Boostrap Drupal and islandora.
 */
function _islandora_senior_report_ingest_bootstrap_drupal() {
  $drupal_core_path = DRUSH_DRUPAL_CORE;
  require_once $drupal_core_path . '/includes/bootstrap.inc';
  require_once $drupal_core_path . '/includes/common.inc';
  include_once $drupal_core_path . '/includes/unicode.inc';

  drupal_bootstrap(DRUPAL_BOOTSTRAP_SESSION);
  require_once $drupal_core_path . '/includes/install.inc';
  require_once $drupal_core_path . '/modules/system/system.install';

  include_once $drupal_core_path . '/includes/module.inc';
  drupal_load('module', 'islandora');
  drupal_load('module', 'islandora_newspaper');
  include_once '/srv/www/VRE7/sites/newspapers.lib.unb.ca/modules/islandora/includes/tuque.inc';
}

/**
 * Implements hook_drush_command().
 */
function islandora_senior_report_ingest_drush_command() {
  $items = array();
  $items['islandora_ingest_senior_reports'] = array(
    'description' => "Creates a senior report objects and their derivatives from a DSpace dump.",
    'arguments' => array(
      'import_path' => 'The path to the directory that contains the Dspace simple archive format dump',
      'parent_pid' => 'The PID of the collection that will contain the reports.',
      'base_namespace' => 'The base namespace to use for the reports',
      'fedora_url' => 'The full url, including port number to the fedora repository',
      'fedora_user' => 'A user with full write access to the fedora repository',
      'fedora_password' => 'Password for the fedora user',
      'marcorg_id' => 'The content creator marcorg ID code',
    ),
    'examples' => array(
      'drush -u 1 --root=/srv/www/VRE7 --uri=http://localhost islandora_ingest_senior_reports /mnt/dspace_export engineering:senior-reports engineering-senior-reports http://localhost:8080/fedora fedoraAdmin password UNBFU',
    ),
    'aliases' => array('ingestreports'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
  );
  return $items;
}

/**
 * Ingest a senior report_set into Fedora.
 *
 * Callback for islandora_senior_report_ingest_drush_command()
 *
 * @param string $import_path
 *   The path that contains the Dspace simple archive format dump
 * @param string $parent_pid
 *   The PID of the collection that will contain the reports
 * @param string $base_namespace
 *   The PID to use for the reports
 * @param string $fedora_url
 *   The full URI (including port number) for the Fedora repository
 * @param string $fedora_user
 *   Username for authentication to the Fedora repository
 * @param string $fedora_password
 *   Password for authentication to the Fedora repository
 *
 * @ingroup callbacks
 */
function drush_islandora_senior_report_ingest_islandora_ingest_senior_reports($import_path, $parent_pid, $base_namespace, $title_string, $fedora_url, $fedora_user, $fedora_password) {
  _islandora_senior_report_ingest_bootstrap_drupal();
  $import = new DspaceSimpleArchiveExport();
}
