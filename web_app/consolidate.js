const fs      = require('fs');
const path    = require('path');
const process = require('process');

const base_dir = process.argv[2];

const html_path = base_dir + '/bundle_template.html';
const js_path   = base_dir + '/web_app.js';

const html = fs.readFileSync(html_path, 'utf8');
const js   = fs.readFileSync(js_path, 'utf8');

const result = html.replace('{{web_app.js}}', () => js);

fs.writeFileSync(base_dir + '/bundle.html', result);
