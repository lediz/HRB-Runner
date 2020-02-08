const path = require('path');

module.exports = {
  entry: './hbrRun.js',
  output: {
    filename: 'hrbRunner.js',
    path: path.resolve(__dirname, 'dist'),
  },
};