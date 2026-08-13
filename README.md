-------------------------------------------------------------------------

<div align="center">
  <p><em>Coding is not always perfect.</em></p>
  <p><em>Feel free to <b>POINT OUT ERRORS</b> and <b>SHARE YOUR IDEAS</b>.</em></p>
  </div>
 

-------------------------------------------------------------------------

<br>

# Project Template

## About
- A project template that contain compare string feature.
- This project deliberately avoids using `string.h`, implementing all conversion logic from scratch. 
- The goal is to remain portable in scenarios lacking standard library support, such as resource-constrained embedded environments. 
- This is a personal toolkit project. Copying, modification, and feedback for improvement are all welcome.

<br>

## Features
- Custom string equality check (`compare_strings`) implemented without `string.h`.
- Cross-file global state (`errorCode`, `i`) shared via `extern` declarations in `function.h` — a minimal, correct pattern for global variables across translation units.

<br>

## Known Limitations
- `compare_strings` only tells you whether two strings are equal — it does not (and, given its `unsigned int` return type, safely cannot) tell you which one is lexicographically greater. Do not use its return value for sorting.
- `compare_strings` does not check for `NULL` input pointers; passing `NULL` will crash the program.
- Global variables `errorCode` and `i` are not thread-safe.


<br>

## Why No <string.h>?
Most conversion tools directly call standard library functions like `strcmp` for this task. 

This project deliberately writes out the entire string manipulation process by hand with the aims of: 

- Understanding the actual logic behind string manipulation rather than treating it as a black box. 
- Preserving the possibility of porting the code to environments without full C standard library support (such as certain embedded platforms).

<br>

## Folder Structure
- Header file(`.h`) usually saves in `include` folder.
- Source file(`.c`) usually saves in `src` folder.

-----------------------------------------------------------------------------------------------------------

	├── include/
	│   └── function.h
	├── src/
	│   └── compare-strings.c
	│   └── custom-function.c
	├── .github/
	│   └── workflows/
	|		└── test.yml
	├── main.c
	├── README.md
	├── LICENSE
	├── .gitignore
	├── Makefile


<br>

## .gitignore
- It tells tools which file can be ignored.
- It ensures that when someone downloads your repository, they only get the clean, essential files required to run the project.
- You may go to [gitignore.io](https://www.toptal.com/developers/gitignore) to generate .gitignore.
	- Select programming languages, IDE and OS.
 	- Example: C, Visual Studio, Linux, Windows

<br>

## Makefile
- If you create Makefile in text editor, remember save as `Makefile` not `Makefile.txt`
- Without Makefile, user need to type long command to build executable (`gcc`), testing (`./main`) and cleanup (`rm -f`) etc.
- Makefile can add customize shortcut commands.
- To use the commands, run `make[Command Name]`. Example:
	-  	Build the executable --> `make`
 	-  	Run the executable --> `make run` or `make test`
    -   Delete executable --> `make clean`

<br>

## .yml
- GitHub can test coding in Linux, Windows and macOS.
- The configuration files should be stored in `.github/workflows/[File Name].yml`
	- Example: `.github/workflows/test.yml`

<br>

## Testing on local Windows/Linux PC
1. Got to repository page and click `<>Code` --> Download zip
2. Extract the zip
3. Open Command Prompt (Windows) or Terminal (Linux) 
4. Direct to directory which contain `main.c`.
5. Build executable
	- `make`
6. Run executable
	- `make run`
7. Cleanup executable
    - `make clean`

<br>

## Testing on Github
1. After `.yml` is uploaded to repository, GitHub will run your coding automatically.
2. Go to repository page and click `Actions` in top menu.
3. Click the project `Project_Template` at left side menu.
4. GitHub will test coding automatically when push new commit. Click the `[Commit]` to check the workflow log.
	- Example: `Refactor Makefile for improved OS detection and cleanup` 
6. Click the `build on ubuntu-latest` or `build on windows-latest` to check the running log.

<br>

## Example Usage

	i default value:0
	Strings are different
	Hello, World!
	i value in funtion():-99999
	i value in custom_function():1234
	i value in main():2
	Error Codes:0

<br>

## Result
Verified `compare_strings` output across boundary cases (equal, prefix relationships, case sensitivity, empty strings):

| String 1 (`str1`) | String 2 (`str2`) | Result				   |
| ----------------- | ----------------- | ------------------------ |
| string1			| string2			| Strings are different	   |
| hello				| hello				| Strings are equal		   |
| `[Empty]`			| `[Empty]`			| Strings are equal		   |
| abc				| abcd				| Strings are different	   |
| abcd				| abc				| Strings are different	   |
| Hello				| hello				| Strings are different	   |
| `[Empty]`			| a					| Strings are different	   |
| apple				| apply				| Strings are different    |

<br>

## License
1. In GitHub, navigate to the main page of the repository.
2. Click icon `+` > `Create new file` .
3. Name the file `LICENSE` (All capital letters).
4. Button `Choose a license template` appears. Click it.
5. Select the license you want to use 
	- `MIT License` is suitable for coding that will be shared and modified by others.
6. Click `Review and submit` > `Commit changes...` to create the LICENSE file.
7. In README.md, add a section to indicate the license type and link to the LICENSE file.
	- 	This project is licensed under the ` [License Type] ` — see the [LICENSE](LICENSE) file for details.

-----------------------------------------------------------------------------------------------------------

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
