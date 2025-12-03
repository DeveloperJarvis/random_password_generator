# Random Password Generator

A customizable random password generator in C, designed to create secure passwords with various options such as length, inclusion of numbers, symbols, and uppercase letters.

## Features

- **Customizable Password Length**: Set the length of the generated password.
- **Option for Numbers**: Include numeric digits (0-9) in the password.
- **Option for Symbols**: Include special characters such as `!@#$%^&*()`.
- **Uppercase/Lowercase Letters**: Select whether to include uppercase or lowercase letters.
- **Randomization**: Generate a secure, unpredictable password using a pseudo-random number generator.

## Requirements

- C Compiler (e.g., GCC or Clang)
- Standard C Library

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/DeveloperJarvis/random_password_generator.git
   cd random_password_generator
   ```

2. Compile the source code:

   ```bash
   gcc -o random_password_generator random_password_generator.c
   ```

3. Run the executable:

   ```bash
   ./random_password_generator
   ```

## Usage

The program provides several command-line options to customize the generated password:

```bash
./random_password_generator [options]
```

### Options:

- `-l, --length <length>`: Set the length of the generated password. (default: 12)
- `-n, --numbers`: Include numeric digits (0-9) in the password.
- `-s, --symbols`: Include special characters in the password (e.g., `!@#$%^&*()`).
- `-u, --uppercase`: Include uppercase letters (A-Z) in the password.
- `-h, --help`: Display help information.

### Example Usage:

1. **Generate a 16-character password with numbers, symbols, and uppercase letters**:

   ```bash
   ./random_password_generator -l 16 -n -s -u
   ```

2. **Generate a 10-character password with only lowercase letters**:

   ```bash
   ./random_password_generator -l 10
   ```

3. **Generate a 12-character password with symbols and uppercase letters**:

   ```bash
   ./random_password_generator -l 12 -s -u
   ```

## License

This project is licensed under the GNU General Public License v3.0 or later.

You can redistribute and modify it under the terms of the license. See [LICENSE](LICENSE) for more details.

## Contact

- **Author**: Developer Jarvis (Pen Name)
- **GitHub**: [https://github.com/DeveloperJarvis](https://github.com/DeveloperJarvis)
- **Email**: (optional, if you want to add an email for contact)

## Creating tag

```bash
# 1. Check existing tags
git tag
# 2. Create a valid tag
git tag -a v1.0.0 -m "Release version 1.0.0"
# or lightweight tag
git tag v1.0.0
# push tag to remote
git push origin v1.0.0
```
