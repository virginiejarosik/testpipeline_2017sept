<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>




<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>




    <?php foreach ($widgets as $id => $widget): ?>
      <dd>



        <?php if (!empty($widget->label)): ?>
          <h5><?php print $widget->label; ?></h5>

        <?php endif; ?>
        <div class="drop <?php print $widget->id; ?>">
          <?php
          switch ($widget->id) {

              case 'edit-term-node-tid-depth':
                  print $widget->widget;
                  //drupal_add_css(drupal_get_path('theme', 'jagency') . '/css/jquery-ui.css');
                  //print '<input type="text" id="custom_special_interest"/>';
                  //print '<div style="display:none;">' . $widget->widget . '</div>';
                  //print t('ex: photography, hiking, music');
                  //print '<ul class="keywords"></ul>';
                  print '<div class="clear">
              ' . l(t('clear'), '', array('attributes' => array('id' => 'interest_clear'))). '</div>';
                  break;


              case 'edit-field-age-group-target-id':
                  print $widget->widget;
                  print '<div class="clear">
                ' . l(t('clear'), '', array('attributes' => array('id' => 'age_group_clear'))). '</div>';
                  break;

             case 'edit-field-language-target-id':
                  print $widget->widget;
                  print '<div class="clear">
                ' . l(t('All'), '', array('attributes' => array('id' => 'language_all'))). '&nbsp&nbsp&nbsp' . l(t('clear'), '', array('attributes' => array('id' => 'language_clear'))). '</div>';
                  break;



              case 'edit-field-where-do-you-want-togo-target-id':
                  print $widget->widget;
                  print '<div class="clear">
                ' . l(t('clear'), '', array('attributes' => array('id' => 'where_do_you_clear'))). '&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</div>';
                  break;

            case 'edit-field-what-do-you-want-to-do-target-id':

                print $widget->widget;
                print '<div class="clear">
                ' . l(t('All'), '', array('attributes' => array('id' => 'what_do_you_all'))). '&nbsp&nbsp&nbsp' . l(t('clear'), '', array('attributes' => array('id' => 'what_do_you_clear'))). '&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp</div>';
              break;
            case 'edit-field-start-date-value':
                print strip_tags($widget->widget, "<input><img><a><lable>");
                print '<div id="doWhen-datepicker"></div>
                <div class="clear">' . l(t('clear'), '', array('attributes' => array('id' => 'StartValue_clear'))). '</div>';
                
              break;
            case 'edit-field-program-icons-value':
                print $widget->widget;


                print '<div class="clear">
                ' . l(t('All'), '', array('attributes' => array('id' => 'includes_all'))). '&nbsp&nbsp&nbsp' . l(t('clear'), '', array('attributes' => array('id' => 'includes_clear'))). '</div>';
              break;
            case 'edit-field-time-of-year-value':
                print $widget->widget;
                print '<div class="clear">
                ' . l(t('All'), '', array('attributes' => array('id' => 'time_of_year_all'))). '&nbsp&nbsp&nbsp' . l(t('clear'), '', array('attributes' => array('id' => 'time_of_year_clear'))). '</div>';
              break;

            case 'edit-field-total-cost-value':
              print '<div style="display:none;">' . $widget->widget . '</div>';
              print '<div id="totalCost"></div>
              <div class="timeSpanText" id="totalCost_amount"></div>
              <div class="clear">' . l(t('clear'), '', array('attributes' => array('id' => 'totalCost_clear'))). '</div>';
              break;
            case 'edit-field-how-long-value':
              print '<div style="display:none;">' . $widget->widget . '</div>';
              print '<div id="HowLong"></div>
              <div class="timeSpanText" id="HowLong_amount"></div>
              <div class="clear">' . l(t('clear'), '', array('attributes' => array('id' => 'HowLong_clear'))). '</div>';
              break;

            case 'edit-keys':
              print $widget->widget;
              print '<button id="search_submit">'.t('Search').'</button>
              <div class="clear">' . l(t('clear'), '', array('attributes' => array('id' => 'search_clear'))). '</div>';

              break;
            default:
                print $widget->widget;
              break;
          }
          ?>
        </div>
      </dd>
    <?php endforeach; ?>




    <?php if (!empty($sort_by)): ?>
      <div id="Sort_by_opp" class="views-exposed-widget views-widget-sort-by">
        <?php print $sort_by; ?>
      </div>
      <div class="views-exposed-widget views-widget-sort-order">
        <?php print $sort_order; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($items_per_page)): ?>
      <div class="views-exposed-widget views-widget-per-page">
        <?php print $items_per_page; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($offset)): ?>
      <div class="views-exposed-widget views-widget-offset">
        <?php print $offset; ?>
      </div>
    <?php endif; ?>
    <div class="views-exposed-widget views-submit-button">
      <?php print $button; ?>
    </div>
    <?php if (!empty($reset_button)): ?>
      <div class="views-exposed-widget views-reset-button">
        <?php print $reset_button; ?>
      </div>
    <?php endif; ?>