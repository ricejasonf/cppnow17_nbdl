template <>
struct code_syntax<decltype("docker_deps"_s)>
{
  static constexpr char const* const value = 
"...\n"
"<span style=\"color:#0000c0\"># Boost.Hana (c++1z workaround branch)</span>\n"
"<span style=\"color:#af5f00\">RUN</span> git clone -b bugfix/constexpr_arrays &bsol;\n"
"      <span style=\"color:#008080\"><a href=\"https://github.com/ricejasonf/hana.git\">https://github.com/ricejasonf/hana.git</a></span> &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">cp</span> -r hana/include/* /usr/local/src/emscripten/system/include &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">rm</span> -rf hana\n"
"<span style=\"color:#0000c0\"># Kvasir.Mpl</span>\n"
"<span style=\"color:#af5f00\">RUN</span> git clone -b development &bsol;\n"
"      <span style=\"color:#008080\"><a href=\"https://github.com/kvasir-io/mpl.git\">https://github.com/kvasir-io/mpl.git</a></span> &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">cp</span> -r mpl/src/* /usr/local/include &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">cp</span> -r mpl/src/* /usr/local/src/emscripten/system/include &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">rm</span> -rf mpl\n"
"<span style=\"color:#0000c0\"># Nbdl</span>\n"
"<span style=\"color:#af5f00\">RUN</span> git clone -b cppnow17 &bsol;\n"
"      <span style=\"color:#008080\"><a href=\"https://github.com/ricejasonf/nbdl.git\">https://github.com/ricejasonf/nbdl.git</a></span> &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">cp</span> -r nbdl/include/* /usr/local/src/emscripten/system/include &bsol;\n"
"  &amp;&amp; <span style=\"color:#008080\">rm</span> -rf nbdl\n"
"...\n"
;
};
