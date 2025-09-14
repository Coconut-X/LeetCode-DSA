class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // Lambda function to check if a character is a vowel.
        // It converts the char to lowercase first, so it works for both cases.
        auto isvowel = [](const char& c) {
            char lower_c = tolower(c);
            return (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u');
        };

        // Map for exact matches (case-sensitive).
        unordered_map<string, bool> exact_match;
        // Map for case-insensitive matches.
        unordered_map<string, string> case_insensitive_map;
        // Map for vowel-error matches.
        unordered_map<string, string> vowel_error_map;

        for (const string& word : wordlist) {
            exact_match[word] = true;

            string lower_word = word;
            for (char& c : lower_word) {
                c = tolower(c);
            }

            if (case_insensitive_map.find(lower_word) == case_insensitive_map.end()) {
                case_insensitive_map[lower_word] = word;
            }

            string vowel_replaced_word = lower_word;
            for (char& c : vowel_replaced_word) {
                if (isvowel(c)) {
                    c = '*';
                }
            }

            if (vowel_error_map.find(vowel_replaced_word) == vowel_error_map.end()) {
                vowel_error_map[vowel_replaced_word] = word;
            }
        }

        vector<string> result;
        for (const string& query : queries) {

            if (exact_match.find(query) != exact_match.end()) {
                result.push_back(query);
                continue;
            }

            string lower_query = query;
            for (char& c : lower_query) {
                c = tolower(c);
            }
            if (case_insensitive_map.find(lower_query) != case_insensitive_map.end()) {
                result.push_back(case_insensitive_map[lower_query]);
                continue;
            }

            string vowel_replaced_query = lower_query;
            for (char& c : vowel_replaced_query) {
                if (isvowel(c)) {
                    c = '*';
                }
            }
            if (vowel_error_map.find(vowel_replaced_query) != vowel_error_map.end()) {
                result.push_back(vowel_error_map[vowel_replaced_query]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }
};