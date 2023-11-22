#include "tglang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum TglangLanguage tglang_detect_programming_language(const char *text) {
    // Define the command to run the Python script
    char command[256];
    snprintf(command, sizeof(command), "python3 tester.py \"%s\"", text);

    // Execute the Python script and capture its output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        // Handle error
        return TGLANG_LANGUAGE_OTHER;
    }

    char output[32];
    if (fgets(output, sizeof(output), fp) == NULL) {
        // Handle error
        pclose(fp);
        return TGLANG_LANGUAGE_OTHER;
    }

    // Close the process
    pclose(fp);


    // Convert the output to an integer
    int predicted_index = atoi(output);

    // Define an array of language names
    const char *language_names[] = {
        "ada", "asp", "assembly", "bash", "c", "clojure", "cmake", "cobol", "common-lisp",
        "cpp", "csharp", "css", "dart", "dockerfile", "elixir", "emacs-lisp", "erlang",
        "fortran", "fsharp", "go", "graphql", "haskell", "html", "java", "js", "json",
        "julia", "kotlin", "lua", "makefile", "markdown", "mathematica", "matlab", "ocaml", "pascal",
        "perl", "php", "powershell", "prolog", "python", "r", "ruby", "rust", "scala", "scheme",
        "smalltalk", "solidity", "sql", "swift", "tex", "typescript", "verilog", "visual-basic", "xml", "yaml",
    };

    int num_languages = sizeof(language_names) / sizeof(language_names[0]);

    if (predicted_index >= 0 && predicted_index < num_languages) {
        // Use the predicted index to fetch the language name
        const char *predicted_language = language_names[predicted_index];

        // Compare the predicted_language with the language names using if-else statements
        if (strcmp(predicted_language, "ada") == 0) {
            return TGLANG_LANGUAGE_ADA;
        } else if (strcmp(predicted_language, "asp") == 0) {
            return TGLANG_LANGUAGE_ASP;
        } else if (strcmp(predicted_language, "assembly") == 0) {
            return TGLANG_LANGUAGE_ASSEMBLY;
        } else if (strcmp(predicted_language, "bash") == 0) {
            return TGLANG_LANGUAGE_SHELL;
        } else if (strcmp(predicted_language, "c") == 0) {
            return TGLANG_LANGUAGE_C;
        } else if (strcmp(predicted_language, "clojure") == 0) {
            return TGLANG_LANGUAGE_CLOJURE;
        } else if (strcmp(predicted_language, "cmake") == 0) {
            return TGLANG_LANGUAGE_CMAKE;
        } else if (strcmp(predicted_language, "cobol") == 0) {
            return TGLANG_LANGUAGE_COBOL;
        } else if (strcmp(predicted_language, "common-lisp") == 0) {
            return TGLANG_LANGUAGE_COMMON_LISP;
        } else if (strcmp(predicted_language, "cpp") == 0) {
            return TGLANG_LANGUAGE_CPLUSPLUS;
        } else if (strcmp(predicted_language, "csharp") == 0) {
            return TGLANG_LANGUAGE_CSHARP;
        } else if (strcmp(predicted_language, "css") == 0) {
            return TGLANG_LANGUAGE_CSS;
        } else if (strcmp(predicted_language, "dart") == 0) {
            return TGLANG_LANGUAGE_DART;
        } else if (strcmp(predicted_language, "dockerfile") == 0) {
            return TGLANG_LANGUAGE_DOCKER;
        } else if (strcmp(predicted_language, "elixir") == 0) {
            return TGLANG_LANGUAGE_ELIXIR;
        } else if (strcmp(predicted_language, "emacs-lisp") == 0) {
            return TGLANG_LANGUAGE_LISP;
        } else if (strcmp(predicted_language, "erlang") == 0) {
            return TGLANG_LANGUAGE_ERLANG;
        } else if (strcmp(predicted_language, "fortran") == 0) {
            return TGLANG_LANGUAGE_FORTRAN;
        } else if (strcmp(predicted_language, "fsharp") == 0) {
            return TGLANG_LANGUAGE_FSHARP;
        } else if (strcmp(predicted_language, "go") == 0) {
            return TGLANG_LANGUAGE_GO;
        } else if (strcmp(predicted_language, "graphql") == 0) {
            return TGLANG_LANGUAGE_GRAPHQL;
        } else if (strcmp(predicted_language, "haskell") == 0) {
            return TGLANG_LANGUAGE_HASKELL;
        } else if (strcmp(predicted_language, "html") == 0) {
            return TGLANG_LANGUAGE_HTML;
        } else if (strcmp(predicted_language, "java") == 0) {
            return TGLANG_LANGUAGE_JAVA;
        } else if (strcmp(predicted_language, "js") == 0) {
            return TGLANG_LANGUAGE_JAVASCRIPT;
        } else if (strcmp(predicted_language, "json") == 0) {
            return TGLANG_LANGUAGE_JSON;
        } else if (strcmp(predicted_language, "julia") == 0) {
            return TGLANG_LANGUAGE_JULIA;
        } else if (strcmp(predicted_language, "kotlin") == 0) {
            return TGLANG_LANGUAGE_KOTLIN;
        } else if (strcmp(predicted_language, "lua") == 0) {
            return TGLANG_LANGUAGE_LUA;
        } else if (strcmp(predicted_language, "makefile") == 0) {
            return TGLANG_LANGUAGE_MAKEFILE;
        } else if (strcmp(predicted_language, "markdown") == 0) {
            return TGLANG_LANGUAGE_MARKDOWN;
        } else if (strcmp(predicted_language, "mathematica") == 0) {
            return TGLANG_LANGUAGE_WOLFRAM;
        } else if (strcmp(predicted_language, "matlab") == 0) {
            return TGLANG_LANGUAGE_MATLAB;
        } else if (strcmp(predicted_language, "ocaml") == 0) {
            return TGLANG_LANGUAGE_OCAML;
        } else if (strcmp(predicted_language, "pascal") == 0) {
            return TGLANG_LANGUAGE_PASCAL;
        } else if (strcmp(predicted_language, "perl") == 0) {
            return TGLANG_LANGUAGE_PERL;
        } else if (strcmp(predicted_language, "php") == 0) {
            return TGLANG_LANGUAGE_PHP;
        } else if (strcmp(predicted_language, "powershell") == 0) {
            return TGLANG_LANGUAGE_POWERSHELL;
        } else if (strcmp(predicted_language, "prolog") == 0) {
            return TGLANG_LANGUAGE_PROLOG;
        } else if (strcmp(predicted_language, "python") == 0) {
            return TGLANG_LANGUAGE_PYTHON;
        } else if (strcmp(predicted_language, "r") == 0) {
            return TGLANG_LANGUAGE_R;
        } else if (strcmp(predicted_language, "ruby") == 0) {
            return TGLANG_LANGUAGE_RUBY;
        } else if (strcmp(predicted_language, "rust") == 0) {
            return TGLANG_LANGUAGE_RUST;
        } else if (strcmp(predicted_language, "scala") == 0) {
            return TGLANG_LANGUAGE_SCALA;
        } else if (strcmp(predicted_language, "scheme") == 0) {
            return TGLANG_LANGUAGE_SCHEME;
        } else if (strcmp(predicted_language, "smalltalk") == 0) {
            return TGLANG_LANGUAGE_SMALLTALK;
        } else if (strcmp(predicted_language, "solidity") == 0) {
            return TGLANG_LANGUAGE_SOLIDITY;
        } else if (strcmp(predicted_language, "sql") == 0) {
            return TGLANG_LANGUAGE_SQL;
        } else if (strcmp(predicted_language, "swift") == 0) {
            return TGLANG_LANGUAGE_SWIFT;
        } else if (strcmp(predicted_language, "tex") == 0) {
            return TGLANG_LANGUAGE_LATEX;
        } else if (strcmp(predicted_language, "typescript") == 0) {
            return TGLANG_LANGUAGE_TYPESCRIPT;
        } else if (strcmp(predicted_language, "verilog") == 0) {
            return TGLANG_LANGUAGE_VERILOG;
        } else if (strcmp(predicted_language, "visual-basic") == 0) {
            return TGLANG_LANGUAGE_VISUAL_BASIC;
        } else if (strcmp(predicted_language, "xml") == 0) {
            return TGLANG_LANGUAGE_XML;
        } else if (strcmp(predicted_language, "yaml") == 0) {
            return TGLANG_LANGUAGE_YAML;
        }
    }
    
    // If the predicted index is out of bounds or doesn't match any language, return TGLANG_LANGUAGE_OTHER
    return TGLANG_LANGUAGE_OTHER;
}
