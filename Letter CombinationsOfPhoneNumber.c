/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize) {
    if (!digits || *digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    char *map[] = {
        "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int len = strlen(digits);
    int total = 1;
    for (int i = 0; i < len; i++)
        total *= strlen(map[digits[i] - '0']);

    char **result = (char **)malloc(sizeof(char *) * total);
    for (int i = 0; i < total; i++)
        result[i] = (char *)malloc(len + 1);

    *returnSize = total;

    int repeat = total;
    for (int i = 0; i < len; i++) {
        char *letters = map[digits[i] - '0'];
        int numLetters = strlen(letters);
        repeat /= numLetters;
        for (int j = 0; j < total; j++) {
            result[j][i] = letters[(j / repeat) % numLetters];
        }
    }

    for (int i = 0; i < total; i++)
        result[i][len] = '\0';

    return result;
}
