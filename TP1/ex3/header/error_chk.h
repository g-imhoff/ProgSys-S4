#ifndef ERROR_CHK_H
#define ERROR_CHK_H

/**
 * @brief This function check if there is an error
 *
 * This function will check if the param is really an error code, and if it is,
 * will print an error message and stop the program with the error_code as
 * status param
 *
 * @param error_code This param contains the error code that will determine
 * which error it is
 */

void error_chk(int error_code);

#endif