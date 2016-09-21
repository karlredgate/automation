
That is how Browserify transforms work, transforms only have an
effect directly in the module that is being referenced.

If you want a module in node_modules to have a transform, you'd
need to add a `package.json` to that module and add babelify as a
transform for that module too. e.g.

```
"browserify": {
"transform": [
"babelify"
]
},
```

inside your package.json plus babelify as a dependency will tell
browserify to run the babelify transform on any file inside that
module.

Having libs be a folder in `node_modules` is however probably a bad
idea. Generally that folder would have true standalone modules in
it. I'd generally say that if the folder can't be taken and reused
elsewhere, then it shouldn't be in `node_modules`.

Update

For Babel v6, which was recently released, you will also need to
specify which transformations you would like to perform on your
code. For that, I would recommend creating a `.babelrc` file in
your root directory to configure Babel.

```
{
"presets": ["es2015"]
}
```

and

```
npm install --save-dev babel-preset-es2015
```

