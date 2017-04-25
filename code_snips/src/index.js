const fs          = require('fs')
const inline_css  = require('inline-css')
const hljs        = require('./highlightjs')
const highlight   = hljs.highlight

const escape_quotes = (html) => html.replace(/"/g, '\\"')
const get_code_file = (name) => fs.readFileSync('../code/' + name, 'utf8')
const stylize = (css, html) => inline_css(html, { url: 'm', extraCss: css, removeHtmlSelectors: true })
const to_hana_string = (str) => "hana::string<'" + str.split('').join("', '") + "'>"
const to_string_literal = (html) => '\n    "' + html.split('\n').join('\\n"\n    "') + '"'

const specialize = (name, string_literal) => [
  'template<>\nstruct code_syntax<', to_hana_string(name), '>  {\n'
, '  static constexpr char const* const value = ' , string_literal, ';\n};'
].join('')

const get_inlined = (name) => stylize(fs.readFileSync('./highlightjs/styles/ir-black.css'),
                              ((hl_result) => hl_result.value)(
                              highlight('cpp',
                              get_code_file(
                              name
                              )))).then((html) => specialize(name,
                                                   to_string_literal(
                                                   escape_quotes(
                                                   html
                                                   ))))

Promise.all(fs.readdirSync('../code/').map(get_inlined))
.then((parts) => fs.writeFileSync('../output.hpp', parts.join('\n\n')))
.catch((err) => console.log('REJECTION: ', err))
