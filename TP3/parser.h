/*
 * parser.h
 *
 *  Created on: 7 nov. 2020
 *      Author: Lucasdamiann
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);
int parser_IdFromText(FILE *pFile);

#endif /* PARSER_H_ */
