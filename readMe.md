# Harbour portable files javascript runner
**hrbRunner.js** is a javascript module to run hrb files called Harbour portable file.
## How to use
download the lasted version of hrbRunner.js from this releases and include it on your html file in this way:
```html
<script src="hrbRunner.js"></script>
```
inside the head tag.

Then it is possible load the desired file with this command:
```js
var promise = (new HRB()).download("test1.hrb")
```
the download method returns a [promise](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise). When fulfilled it calls the resolved callback the the hrb object in it. See test1 for a usage example.

It is possible automatically download the hrb files including it on header in this way:
```html
<script src="directHB.hrb" type="harbour/hrb"></script>
```
When the DOM is loaded all script of type *harbour/hrb* will be loaded by the hrbRunner and the first function is executed.

**It is necessary a file server to run a hrb file.**

## How to create hrb files
To create an hrb files it is sufficient run harbour
```shell
harbour file.prg -gh
```
add others command switch if needed.
## Hot to build the hrbRunner from source
To build this project is necessary a working node installation then from the source folder run
```shell
npm install
```
to install webpack.
Now you have a working source folder, then do
```shell
npm run prelanch
```
to create a develop hrbRunner.js, or do
```shell
npm run prerelease
```
to create a releasable hrbRunner.js.
