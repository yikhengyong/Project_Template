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


<br>

## Known Limitations



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
	├── main.c
	├── README.md


<br>

## Example Usage

	i default value:0
	Strings are different
	Hello, World!
	i value in funtion():-99999
	i value in funtion_in_src():1234
	i value in main():2
	Error Codes:0

<br>

## Result



<br>

## License

1. In GitHub, navigate to the main page of the repository.
2. Click icon `+` > `Create new file` .
3. Name the file `LICENSE` (All capital letters).
4. Button `Choose a license template` appears. Click it.
5. Select the license you want to use 
	- `MIT License` is suitable for coding that will be shared and modified by others.
6. Click `Review and submit` > `Commit new file` to create the LICENSE file.
7. In README.md, add a section to indicate the license type and link to the LICENSE file.
	- 	This project is licensed under the ` [License Type] ` — see the [LICENSE](LICENSE) file for details.

-----------------------------------------------------------------------------------------------------------

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.
