/** \brief Abre el archivo data.csv en modo de lectura de texto y llama a la funcion parser_EmployeeFromText()
           que lee los archivos y los guarda en la LinkedList
 *
 * \param path char* Nombre del archivo y tipo del mismo
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Abre el archivo data.bin en modo de lectura binario y llama a la funcion parser_EmployeeFromBinary();
 *
 * \param path char* Nombre del archivo y tipo del mismo
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega un empleado a la LinkedList creado en memoria dinamica con la funcion employee_new(); creando su id mediante la funcion
 *         createEmployeeId(); y pidiendo los datos del empleado al usuario
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Pide el id para modifica un empleado, busca y desplega un menu para modificar cada campo, si se guardan los cambios, se pasan todos los
 *         datos guardados en variables auxiliares al empleado original en la LinkedList
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Pide un id para eliminar un empleado, busca y pregunta si se desea eliminar, si la respuesta es afirmativa llama a la funcion
 *         ll_remove(); y elimina a ese empleado, sino, lo cancela
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Lista a todos los empleados guardados en la LinkedList usando un for y la funcion ll_get(); guardando en un auxiliar de tipo empleado
 *         cada uno de los mismos e imprimiendolos
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordena la lista de empleados llamando a las funciones employee_CompareByName(); y employee_CompareById();
 *         Las cuales establecen la comparacion entre los mismos
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda la LinkedList en el archivo de texto
 *
 * \param path char* Nombre del archivo y tipo del mismo
 * \param pArrayListEmployee LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int Retorna 1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda la LinkedList en el archivo Binario
 *
 * \param path char* Nombre del archivo y tipo del mismo
 * \param pArrayListEmployee LinkedList* LinkedList* La LinkedList sobre la cual se esta trabajando
 * \return int int Retorna 1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


