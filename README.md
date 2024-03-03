# otus_hw7

# Инструкция по сборке:
1. Нужно собрать CASH cmake'а. Если вы работаете по https c github, то CASH надо собирать с дополнительным аргументом -DIS_HTTPS:BOOL=TRUE
2. Выполнить билд кастомной цели CLONE_PROJECTS
3. Билдить основную цель vl_unit_tests