
SLIDE WITH STYLE
================

This module heavily borrows from the SliderField module whose maintainers and
contributors are gratefully acknowledged.

Focus and context of this module are different form SliderField, though.

While SliderField is about the data input and storage aspects of numeric fields,
Slide with Style is about search FILTERS for your fields, in particular
RANGE filters, for fields that are themselves NOT ranges, like numbers or list
fields.

You'll see the widget pop up under the name "Slider" in the widget select
drop-down of fields of the number (integer, float, decimal) or list (text,
number) types. After you have selected it, you'll be given a number of options
to affect its appearance like orientation (horizontal or vertical) and whether
to show an edit field and/or value balloon next to the slider bar. You may
also choose a colour/styling scheme. When different slider widgets appear on
the same page they will share the same colour scheme.

When the widget is used as a filter (e.g. in combination with Views Global
Filter) the slider automatically becomes a RANGE slider with two sliding
handles to set "from" and "to" range values. The edit field of range sliders,
if configured to be displayed, will be read-only.

If the slider widget is chosen for a LIST field, make sure that when defininng
the allowed values at admin/structure/types/manage/<content-type>/fields/<field>/field-settings,
the keys are consecutive integers, as the slider will assume a step size of 1
between the keys.

Example:

  1|Baby
  2|Toddler
  3|Child
  4|Teenager
  5|Adult
  6|Middle-aged
  7|Retiree