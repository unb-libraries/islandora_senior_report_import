# Islandora Senior Report Ingest
This drush command leverages the Islandora Thesis Solution Pack to ingest a senior report object into a fedora commons repository.

This development was based on a model originally written by Paul Pound at UPEI (https://github.com/roblib/scripts/blob/master/drush/drupal7/islandora_newspapers.drush.inc).

Some assumptions about the source data are made for the sake of sanity:
+   All data must be exported into a DSpace Simple Archive Format

## Setup
Install this script as a drush command.

## Use
The required arguments, in order, are:
+   import_path : The path to the directory that contains the Dspace simple archive format dump
+   parent_pid : The PID of the collection that will contain the reports.
+   base_namespace : The base namespace to use for the reports
+   fedora_url : The full url, including port number for the fedora repository
+   fedora_user : A user with full write access to the fedora repository
+   fedora_password : Password for the fedora user
+   marcorg_id : The content creator marcorg ID code

```bash
drush -u 1 --root=/srv/www/VRE7 --uri=http://localhost islandora_ingest_senior_reports /mnt/dspace_export engineering:senior-reports engineering-senior-reports http://localhost:8080/fedora fedoraAdmin password UNBFU
```
