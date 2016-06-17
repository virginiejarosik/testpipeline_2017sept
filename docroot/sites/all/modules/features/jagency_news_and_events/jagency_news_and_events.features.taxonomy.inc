<?php
/**
 * @file
 * jagency_news_and_events.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function jagency_news_and_events_taxonomy_default_vocabularies() {
  return array(
    'jewish_agency' => array(
      'name' => 'Jewish Agency',
      'machine_name' => 'jewish_agency',
      'description' => 'The main taxonomy',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
