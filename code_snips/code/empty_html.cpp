auto bulleted_slide = [](auto header, auto ...bullets)
{
  return div(
    attr_class("slide-bulleted"_s)
  , div(
      attr_class("header"_s)
    , text_node(header)
    )
  , ul(li(text_node(bullets))...)
  );
};
