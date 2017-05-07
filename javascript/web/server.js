const express = require('express');
const opn = require('opn');

const app = express();
app.use(express.static('public'));

app.get('/', (req, res) => {
  res.send('Hello World!');
});

app.post('/text', (req, res) => {
  console.log('Button Pressed. Entered text: ' + req.query.text);
  res.end();
});

app.post('/combo', (req, res) => {
  console.log('Combo Box Changed. Selected item: ' + req.query.text);
  res.end();
});

app.post('/checkbox', (req, res) => {
  console.log('Check box ' + req.query.text);
  res.end();
});

app.post('/radio', (req, res) => {
  console.log('Radio ' + req.query.text + ' checked');
  res.end();
});

app.post('/slider', (req, res) => {
  console.log('Slider slid to ' + req.query.text);
  res.end();
});

app.post('/spinner', (req, res) => {
  console.log('Spinner spun to ' + req.query.text);
  res.end();
});

app.listen(3631, () => {
  console.log('Listening on port 3631!');
  opn('http://localhost:3631/');
});
