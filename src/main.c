#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(
    int argc,
    char** argv
) {
    // Make sure text format is avaiable in clipboard
    if (!IsClipboardFormatAvailable(CF_TEXT)) {
        fputs("Clipboard text format unavailable", stderr);
        return EXIT_FAILURE;
    }

    // Open the clipboard
    if (!OpenClipboard(NULL)) {
        fputs("Failed to open clipboard", stderr);
        return EXIT_FAILURE;
    }

    // Acquire and lock clipboard data
    HGLOBAL const clipboard_data = GetClipboardData(CF_TEXT);
    if (clipboard_data != NULL) 
    {
        LPTSTR clipboard_text = GlobalLock(clipboard_data);

        // Print to stdout
        if (clipboard_text != NULL) {
            fprintf(stdout, "%s", clipboard_text);
        }

        GlobalUnlock(clipboard_data);
    }

    CloseClipboard();
    return EXIT_SUCCESS;
}
