//============================================================================
// Name        : Prueba_serie_win.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <windows.h>
#include <iostream>
using namespace std;


#define STRING_SIZE 100

using std::cout;
using std::cin;

int main()
{
  HANDLE hComPort;
  DWORD dwBytesWritten;
  DWORD dwBytesRead;
  DWORD dwBufferSize;
  TCHAR szBuffer[STRING_SIZE];
  DWORD dwBufferRead;

  dwBufferSize = sizeof(TCHAR) * STRING_SIZE;

 /* hComPort = CreateFile("COM3",
                  GENERIC_READ | GENERIC_WRITE, // solo pueden ser estos valores
                  0,
                  0,
                  OPEN_EXISTING, // solo puede ser OPEN_EXISTING
                  FILE_FLAG_OVERLAPPED,
                  0);*/
  hComPort =  CreateFileA ("\\\\.\\COM2", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
  if (hComPort == INVALID_HANDLE_VALUE)
  {    // no se pudo abrir el puerto COM3:
	  printf ("fail CreateFile: %d\n", GetLastError ()); system ("pause"); return 0;
  }
  else
  {

      // leer datos desde el puerto serial
      ReadFile(hComPort, szBuffer, dwBufferSize, &dwBufferRead, NULL);
      cout << "Se leyeron " << dwBufferRead << " bytes. " <<
                    "Buffer: " << szBuffer << endl;

      // etcétera: podemos emplear WriteFile para escribir bytes.
  }

  // finalmente, cerramos el manejador
  CloseHandle(hComPort);

  return EXIT_SUCCESS;
}
