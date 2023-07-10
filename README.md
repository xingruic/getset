# getset
Small project i did while taking a java course. The "encapsulate fields" thing in intellij or the similiar thing in vscode didn't generate basic comments that describe what the getters and setters do, but the java course required comments for every function.
```
usage: getset.exe <filename>
```

### What exactly does it do
It generates getters and setters for every line that starts with `private` (excluding whitespace) and includes a semicolon. That was enough for my purposes.
It puts the getters and setters directly before the first line that only contains a `}`, including whitespace.

### What does this do to the file?
The file you feed it won't be changed. Let's say you give it `filename.extension`, it will write to the file called `filename_encapsulated.extension`.