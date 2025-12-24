/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .tests.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foehler <foehler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:55:19 by foehler           #+#    #+#             */
/*   Updated: 2025/12/24 18:17:02 by foehler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h> // Necesario para INT_MAX, INT_MIN
#include "ft_printf.h"

#define TEST_MSG " -> Retorno: %d\n"

int main(void)
{
    int ret_orig;
    int ret_ft;
    int a = 42;
    void *ptr = &a;

    // Desactivamos buffer
    setbuf(stdout, NULL);

    printf("\n========================================\n");
    printf("===      TESTS BÁSICOS (TEXTO)       ===\n");
    printf("========================================\n\n");

    // --- TEST 1: Texto Simple ---
    printf("--- TEST 1: Texto Simple ---\n");
    printf("printf:    "); ret_orig = printf("Hola mundo!"); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("Hola mundo!"); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===      CONVERSIONES CHAR (c)      ===\n");
    printf("========================================\n\n");

    // --- TEST: Caracter simple ---
    printf("--- Char simple 'a' ---\n");
    printf("printf:    "); ret_orig = printf("%c", 'a'); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%c", 'a'); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- TEST: Caracter null (caso tricky) ---
    // El caracter nulo debe imprimir algo invisible pero contar como 1
    printf("--- Char nulo (0) ---\n");
    printf("printf:    "); ret_orig = printf("null: %c", 0); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("null: %c", 0); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===     CONVERSIONES STRING (s)     ===\n");
    printf("========================================\n\n");

    // --- TEST: String normal ---
    printf("--- String normal ---\n");
    printf("printf:    "); ret_orig = printf("%s", "Cadena de prueba"); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%s", "Cadena de prueba"); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- TEST: String NULL ---
    // IMPORTANTE: printf original en Linux imprime "(null)", en Mac a veces crashea.
    // 42 suele pedir que se imprima "(null)"
    printf("--- String NULL ---\n");
    printf("printf:    "); ret_orig = printf("%s", (char *)NULL); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%s", (char *)NULL); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===    ENTEROS DECIMALES (d i)     ===\n");
    printf("========================================\n\n");

    // --- TEST: Enteros básicos ---
    printf("--- Entero positivo y negativo ---\n");
    printf("printf:    "); ret_orig = printf("%d, %i", 1234, -1234); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%d, %i", 1234, -1234); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- TEST: Límites (INT_MIN, INT_MAX) ---
    printf("--- Limites INT ---\n");
    printf("printf:    "); ret_orig = printf("%d, %d", INT_MAX, INT_MIN); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%d, %d", INT_MAX, INT_MIN); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- TEST: Cero ---
    printf("--- Cero ---\n");
    printf("printf:    "); ret_orig = printf("Es %d", 0); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("Es %d", 0); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===        UNSIGNED (u)             ===\n");
    printf("========================================\n\n");

    printf("--- Unsigned normal y maximo ---\n");
    printf("printf:    "); ret_orig = printf("%u, %u", 42, UINT_MAX); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%u, %u", 42, UINT_MAX); printf(TEST_MSG, ret_ft);
    printf("\n");

    // Probamos pasar un negativo a %u (debe mostrar el valor casteado a unsigned, numero grande)
    printf("--- Negativo en Unsigned ---\n");
    printf("printf:    "); ret_orig = printf("%u", -42); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%u", -42); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===      HEXADECIMAL (x X)         ===\n");
    printf("========================================\n\n");

    printf("--- Hex minuscula y mayuscula ---\n");
    printf("printf:    "); ret_orig = printf("%x, %X", 255, 255); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%x, %X", 255, 255); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("--- Hex 0 ---\n");
    printf("printf:    "); ret_orig = printf("%x", 0); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%x", 0); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===         PUNTEROS (p)            ===\n");
    printf("========================================\n\n");

    printf("--- Puntero valido ---\n");
    printf("printf:    "); ret_orig = printf("%p", ptr); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%p", ptr); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("--- Puntero NULL ---\n");
    printf("printf:    "); ret_orig = printf("%p", NULL); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%p", NULL); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===       PORCENTAJE (%%)             ===\n");
    printf("========================================\n\n");

    printf("--- Porcentajes ---\n");
    printf("printf:    "); ret_orig = printf("100%% puro"); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("100%% puro"); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===     TESTS DE FLAGS (# + space)   ===\n");
    printf("========================================\n\n");

    // --- Flag # ---
    // Solo afecta a x, X. Añade 0x o 0X. Si es 0 no añade nada.
    printf("--- Flag # (Hash) con x y X ---\n");
    printf("printf:    "); ret_orig = printf("%#x, %#X", 42, 42); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%#x, %#X", 42, 42); printf(TEST_MSG, ret_ft);
    
    printf("--- Flag # con valor 0 (no debe poner prefijo) ---\n");
    printf("printf:    "); ret_orig = printf("%#x", 0); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%#x", 0); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- Flag + ---
    // Fuerza el signo en positivos.
    printf("--- Flag + (Plus) con d e i ---\n");
    printf("printf:    "); ret_orig = printf("%+d, %+d", 42, -42); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%+d, %+d", 42, -42); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- Flag ' ' (Espacio) ---
    // Pone un espacio si es positivo, signo si es negativo.
    printf("--- Flag ' ' (Espacio) ---\n");
    printf("printf:    "); ret_orig = printf("% d, % d", 42, -42); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("% d, % d", 42, -42); printf(TEST_MSG, ret_ft);
    printf("\n");

    // --- Prioridad + sobre ' ' ---
    // Si están los dos, gana el +.
    printf("--- Flag + y ' ' juntos (gana +) ---\n");
    printf("printf:    "); ret_orig = printf("%+d", 42); printf(TEST_MSG, ret_orig);
    printf("ft_printf: "); ret_ft = ft_printf("%+ d", 42); printf(TEST_MSG, ret_ft);
    printf("\n");

    printf("\n========================================\n");
    printf("===          TEST MIXTO              ===\n");
    printf("========================================\n\n");

    printf("printf:    "); 
    ret_orig = printf("Char: %c, Str: %s, Int: %d, Hex: %#x", 'Z', "Mix", 10, 255); 
    printf(TEST_MSG, ret_orig);

    printf("ft_printf: "); 
    ret_ft = ft_printf("Char: %c, Str: %s, Int: %d, Hex: %#x", 'Z', "Mix", 10, 255); 
    printf(TEST_MSG, ret_ft);

    return (0);
}