The fine granularity of control over cache tables and function makes this 
module the ultimate tool to clear the Drupal caches.

It ships with a predefined set of actions, but it's biggest strength lays 
in it's configuration, where one can build any number of custom presets to 
fit almost any need on both development and production environments.
It is suitable for any role, starting from developers to administrators or 
editors. Access to each preset can be limited by permissions.

It allows mixing core and contrib cache tables and/or functions with low 
level custom rules to always clear just what's necessary, reducing precious 
development time.
Using this module minimizes time spent waiting for all the caches to be 
cleared when you a just need to recognize a new template file, for ex.

Integration

It fully integrates with the Drupal 7 core admin menu,
and also with the popular Administration Menu module.
How to use

* download the module and place it under 'sites/all/modules/contrib' 
  folder with Drush use: drush dl cacheflush
* enable the module from the modules page: 'admin/build/modules'
* configure the setting at the bottom of the page under 
  'admin/config/development/cacheflush'
