#include <iostream>
#include <iterator>
#include <regex>
#include <string>

void find_match(const std::vector<std::string>& strings,
                const std::string& exp) {
    std::regex regex(exp);
    std::cout << "Regex = " << exp << std::endl;
    for (auto string : strings) {
        std::cout << "regex_match\t" << string << "\t"
                  << std::regex_match(string, regex) << std::endl;
    }
    std::cout << std::endl;
}

void capture_match(const std::vector<std::string>& strings,
                   const std::string& exp) {
    std::regex regex(exp);
    std::cout << "Regex = " << exp << std::endl;
    std::smatch matches;
    for (auto string : strings) {
        std::cout << "regex_match\t" << string << "\t"
                  << std::regex_match(string, matches, regex) << " ";
        for (int i = 1; i < matches.size(); i++) {
            std::cout << matches[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    {
        std::cout << "-----TASK 1-----" << std::endl;
        std::vector<std::string> strings = {"abcdefg", "abcde", "abc"};
        std::string expr = "abc.*";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 1.2-----" << std::endl;
        std::vector<std::string> strings = {"abc123xyz", "define \"123\"",
                                            "var g = 123;"};
        std::string expr = ".*123.*";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 2-----" << std::endl;
        std::vector<std::string> strings = {"cat.", "896.", "?=+.", "abc1"};
        std::string expr = ".*\\.";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 3-----" << std::endl;
        std::vector<std::string> strings = {"can", "man", "fan",
                                            "dan", "ran", "pan"};
        std::string expr = "[cmf]an";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 4-----" << std::endl;
        std::vector<std::string> strings = {"hog", "dog", "bog"};
        std::string expr = "[^b]og";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 5-----" << std::endl;
        std::vector<std::string> strings = {"Ana", "Bob", "Cpc",
                                            "aax", "bby", "ccz"};
        std::string expr = "[A-Z][a-z][a-z]";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 6-----" << std::endl;
        std::vector<std::string> strings = {"wazzzzzup", "wazzzup", "wazup"};
        std::string expr = "waz{3,5}up";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 7-----" << std::endl;
        std::vector<std::string> strings = {"aaaabcc", "aabbbbc", "aacc", "a"};
        std::string expr = "a+b*c+";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 8-----" << std::endl;
        std::vector<std::string> strings = {"1 file found?", "2 files found?",
                                            "24 files found?",
                                            "No files found."};
        std::string expr = "\\d\\d? files? found\\?";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 9-----" << std::endl;
        std::vector<std::string> strings = {"1.   abc", "2.	abc",
                                            "3.           abc", "4.abc"};
        std::string expr = "\\d\\.\\s+abc";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 10-----" << std::endl;
        std::vector<std::string> strings = {
            "Mission: successful", "Last Mission: unsuccessful",
            "Next Mission: successful upon capture of target"};
        std::string expr = "^Mission.*";
        find_match(strings, expr);
    }

    {
        std::cout << "-----TASK 11-----" << std::endl;
        std::vector<std::string> strings = {"file_record_transcript.pdf",
                                            "file_07241999.pdf",
                                            "testfile_fake.pdf.tmp"};
        std::string expr = "(.*)\\.pdf$";
        capture_match(strings, expr);
    }

    {
        std::cout << "-----TASK 12-----" << std::endl;
        std::vector<std::string> strings = {"Jan 1987", "May 1969", "Aug 2011"};
        std::string expr = "(\\w...(\\d+))";
        capture_match(strings, expr);
    }

    {
        std::cout << "-----TASK 13-----" << std::endl;
        std::vector<std::string> strings = {"1280x720", "1920x1600",
                                            "1024x768"};
        std::string expr = "(\\d+)x(\\d+)";
        capture_match(strings, expr);
    }

    {
        std::cout << "-----TASK 14-----" << std::endl;
        std::vector<std::string> strings = {"I love cats", "I love dogs",
                                            "I love logs", "I love cogs"};
        std::string expr = "I love (cats)|(dogs)";
        capture_match(strings, expr);
    }

    return 0;
}
