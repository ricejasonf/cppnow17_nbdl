module.exports = function(hljs) {

  var nbdl_words = [
    // namespaces
    'boost', 'hana', 'nbdl', 'nbdl_def', 'ui_spec', 'webui', 'html',

    // hana
    'accessors',
    'adapt_adt',
    'adapt_struct',
    'adjust',
    'adjust_if',
    'all',
    'all_of',
    'and',
    'any',
    'any_of',
    'ap',
    'append',
    'assert',
    'at',
    'at_key',
    'back',
    'basic_tuple',
    'bool',
    'cartesian_product',
    'chain',
    'comparing',
    'concat',
    'concept',
    'contains',
    'core',
    'count',
    'count_if',
    'cycle',
    'define_struct',
    'difference',
    'div',
    'drop_back',
    'drop_front',
    'drop_front_exactly',
    'drop_while',
    'duplicate',
    'empty',
    'equal',
    'erase_key',
    'eval',
    'eval_if',
    'extend',
    'extract',
    'fill',
    'filter',
    'find',
    'find_if',
    'first',
    'flatten',
    'fold',
    'fold_left',
    'fold_right',
    'for_each',
    'front',
    'fuse',
    'greater',
    'greater_equal',
    'group',
    'index_if',
    'if',
    'insert',
    'insert_range',
    'integral_constant',
    'intersection',
    'intersperse',
    'is_disjoint',
    'is_empty',
    'is_subset',
    'keys',
    'lazy',
    'length',
    'less',
    'less_equal',
    'lexicographical_compare',
    'lift',
    'map',
    'max',
    'maximum',
    'members',
    'min',
    'minimum',
    'minus',
    'mod',
    'monadic_compose',
    'monadic_fold_left',
    'monadic_fold_right',
    'mult',
    'negate',
    'none',
    'none_of',
    'not',
    'not_equal',
    'one',
    'optional',
    'or',
    'ordering',
    'pair',
    'partition',
    'permutations',
    'plus',
    'power',
    'prefix',
    'prepend',
    'product',
    'range',
    'remove',
    'remove_at',
    'remove_if',
    'remove_range',
    'repeat',
    'replace',
    'replace_if',
    'replicate',
    'reverse',
    'reverse_fold',
    'scan_left',
    'scan_right',
    'second',
    'set',
    'size',
    'slice',
    'sort',
    'span',
    'string',
    'suffix',
    'sum',
    'symmetric_difference',
    'take_back',
    'take_front',
    'take_while',
    'tap',
    'then',
    'traits',
    'transform',
    'tuple',
    'type',
    'unfold_left',
    'unfold_right',
    'union',
    'unique',
    'unpack',
    'value',
    'version',
    'while',
    'zero',
    'zip',
    'zip_shortest',
    'zip_shortest_with',
    'zip_with',
    // hana functional
    'always',
    'apply',
    'arg',
    'capture',
    'compose',
    'curry',
    'demux',
    'fix',
    'flip',
    'id',
    'infix',
    'iterate',
    'lockstep',
    'on',
    'overload',
    'overload_linearly',
    'partial',
    'placeholder',
    'reverse_partial',

    // hana core
    'common',
    'default',
    'dispatch',
    'is_a',
    'is_an',
    'is_default',
    'make',
    'tag_of',
    'to',
    'when',

    'make_tuple',
    'make_map',
    'make_pair',
    'make_set',

    // nbdl

    'apply_action',
    'apply_delta',
    'apply_foreign_action',
    'bind_map',
    'bind_sequence',
    'bind_variant',
    'catch',
    'context',
    'delta',
    'echo_provider',
    'entity',
    'entity_members',
    'get',
    'make_consumer',
    'make_context',
    'make_def',
    'make_delta',
    'make_provider',
    'make_producer',
    'make_state_consumer',
    'make_store',
    'map_store',
    'throwable_transform',
    'match',
    'match_path',
    'message',
    'message_api',
    'notify_state_change',
    'null_store',
    'pipe',
    'promise',
    'run_async',
    'run_sync',
    'send_downstream_message',
    'send_upstream_message',
    'uid',
    'variant',

    // nbdl concepts

    'BindableMap',
    'BindableSequence',
    'BindableVariant',
    'Consumer',
    'Delta',
    'DownstreamMessage',
    'Entity',
    'Provider',
    'StateConsumer',
    'Store',
    'UpstreamMessage',

    // hana concepts

    'Applicative',
    'Comonad',
    'Comparable',
    'Constant',
    'EuclideanRing',
    'Foldable',
    'Functor',
    'Group',
    'Hashable',
    'IntegralConstant',
    'Iterable',
    'Logical',
    'Metafunction',
    'Monad',
    'MonadPlus',
    'Monoid',
    'Orderable',
    'Product',
    'Ring',
    'Searchable',
    'Sequence',
    'Struct',
  ].join(' ')
  var CPP_PRIMITIVE_TYPES = {
    className: 'keyword',
    begin: '\\b[a-z\\d_]*_t\\b'
  };

  var STRINGS = {
    className: 'string',
    variants: [
      {
        begin: '(u8?|U)?L?"', end: '"',
        illegal: '\\n',
        contains: [hljs.BACKSLASH_ESCAPE]
      },
      {
        begin: '(u8?|U)?R"', end: '"',
        contains: [hljs.BACKSLASH_ESCAPE]
      },
      {
        begin: '\'\\\\?.', end: '\'',
        illegal: '.'
      }
    ]
  };

  var NUMBERS = {
    className: 'number',
    variants: [
      { begin: '\\b(0b[01\']+)' },
      { begin: '(-?)\\b([\\d\']+(\\.[\\d\']*)?|\\.[\\d\']+)(u|U|l|L|ul|UL|f|F|b|B)' },
      { begin: '(-?)(\\b0[xX][a-fA-F0-9\']+|(\\b[\\d\']+(\\.[\\d\']*)?|\\.[\\d\']+)([eE][-+]?[\\d\']+)?)' }
    ],
    relevance: 0
  };

  var PREPROCESSOR =       {
    className: 'meta',
    begin: /#\s*[a-z]+\b/, end: /$/,
    keywords: {
      'meta-keyword':
        'if else elif endif define undef warning error line ' +
        'pragma ifdef ifndef include'
    },
    contains: [
      {
        begin: /\\\n/, relevance: 0
      },
      hljs.inherit(STRINGS, {className: 'meta-string'}),
      {
        className: 'meta-string',
        begin: /<[^\n>]*>/, end: /$/,
        illegal: '\\n',
      },
      hljs.C_LINE_COMMENT_MODE,
      hljs.C_BLOCK_COMMENT_MODE
    ]
  };

  var FUNCTION_TITLE = hljs.IDENT_RE + '\\s*\\(';

  var CPP_KEYWORDS = {
    keyword: 'int float while private char catch import module export virtual operator sizeof ' +
      'dynamic_cast|10 typedef const_cast|10 const for static_cast|10 union namespace ' +
      'unsigned long volatile static protected bool template mutable if public friend ' +
      'do goto auto void enum else break extern using asm case typeid ' +
      'short reinterpret_cast|10 default double register explicit signed typename try this ' +
      'switch continue inline delete alignof constexpr decltype ' +
      'noexcept static_assert thread_local restrict _Bool complex _Complex _Imaginary ' +
      'atomic_bool atomic_char atomic_schar ' +
      'atomic_uchar atomic_short atomic_ushort atomic_int atomic_uint atomic_long atomic_ulong atomic_llong ' +
      'atomic_ullong new throw return ' +
      'and or not',
    built_in: 'std string cin cout cerr clog stdin stdout stderr stringstream istringstream ostringstream ' +
      nbdl_words +
      'auto_ptr deque list queue stack vector map set bitset multiset multimap unordered_set ' +
      'unordered_map unordered_multiset unordered_multimap array shared_ptr abort abs acos ' +
      'asin atan2 atan calloc ceil cosh cos exit exp fabs floor fmod fprintf fputs free frexp ' +
      'fscanf isalnum isalpha iscntrl isdigit isgraph islower isprint ispunct isspace isupper ' +
      'isxdigit tolower toupper labs ldexp log10 log malloc realloc memchr memcmp memcpy memset modf pow ' +
      'printf putchar puts scanf sinh sin snprintf sprintf sqrt sscanf strcat strchr strcmp ' +
      'strcpy strcspn strlen strncat strncmp strncpy strpbrk strrchr strspn strstr tanh tan ' +
      'vfprintf vprintf vsprintf endl initializer_list unique_ptr',
    literal: 'true false nullptr NULL'
  };

  var EXPRESSION_CONTAINS = [
    CPP_PRIMITIVE_TYPES,
    hljs.C_LINE_COMMENT_MODE,
    hljs.C_BLOCK_COMMENT_MODE,
    NUMBERS,
    STRINGS
  ];

  return {
    aliases: ['c', 'cc', 'h', 'c++', 'h++', 'hpp'],
    keywords: CPP_KEYWORDS,
    illegal: '</',
    contains: EXPRESSION_CONTAINS.concat([
      PREPROCESSOR,
      {
        begin: '\\b(deque|list|queue|stack|vector|map|set|bitset|multiset|multimap|unordered_map|unordered_set|unordered_multiset|unordered_multimap|array)\\s*<', end: '>',
        keywords: CPP_KEYWORDS,
        contains: ['self', CPP_PRIMITIVE_TYPES]
      },
      {
        begin: hljs.IDENT_RE + '::',
        keywords: CPP_KEYWORDS
      },
      {
        // This mode covers expression context where we can't expect a function
        // definition and shouldn't highlight anything that looks like one:
        // `return some()`, `else if()`, `(x*sum(1, 2))`
        variants: [
          {begin: /=/, end: /;/},
          {begin: /\(/, end: /\)/},
          {beginKeywords: 'new throw return else', end: /;/}
        ],
        keywords: CPP_KEYWORDS,
        contains: EXPRESSION_CONTAINS.concat([
          {
            begin: /\(/, end: /\)/,
            keywords: CPP_KEYWORDS,
            contains: EXPRESSION_CONTAINS.concat(['self']),
            relevance: 0
          }
        ]),
        relevance: 0
      },
      {
        className: 'function',
        begin: '(' + hljs.IDENT_RE + '[\\*&\\s]+)+' + FUNCTION_TITLE,
        returnBegin: true, end: /[{;=]/,
        excludeEnd: true,
        keywords: CPP_KEYWORDS,
        illegal: /[^\w\s\*&]/,
        contains: [
          {
            begin: FUNCTION_TITLE, returnBegin: true,
            contains: [hljs.TITLE_MODE],
            relevance: 0
          },
          {
            className: 'params',
            begin: /\(/, end: /\)/,
            keywords: CPP_KEYWORDS,
            relevance: 0,
            contains: [
              hljs.C_LINE_COMMENT_MODE,
              hljs.C_BLOCK_COMMENT_MODE,
              STRINGS,
              NUMBERS,
              CPP_PRIMITIVE_TYPES
            ]
          },
          hljs.C_LINE_COMMENT_MODE,
          hljs.C_BLOCK_COMMENT_MODE,
          PREPROCESSOR
        ]
      },
      {
        className: 'class',
        beginKeywords: 'class struct', end: /[{;:]/,
        contains: [
          {begin: /</, end: />/, contains: ['self']}, // skip generic stuff
          hljs.TITLE_MODE
        ]
      }
    ]),
    exports: {
      preprocessor: PREPROCESSOR,
      strings: STRINGS,
      keywords: CPP_KEYWORDS
    }
  };
};