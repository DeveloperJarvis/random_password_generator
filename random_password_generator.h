// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the [Project Name] Library. This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// random_password_generator - Options: length, numbers, symbols, uppercase, etc
// 
// Author: Developer Jarvis (Pen Name)
// Contact: https://github.com/DeveloperJarvis
//
// --------------------------------------------------

#ifndef RANDOM_PASSWORD_GENERATOR_H
#define RANDOM_PASSWORD_GENERATOR_H

#define MIN_LEN 8
// --------------------------------------------------
// forward function declarations/ prototypes
// --------------------------------------------------
void display_help(const char *s);
void display_version(const char *s);

void random_password();
int user_input(int flag);
void clear_input_buffer();
char random_character(int flag);
#endif
