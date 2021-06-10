/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:59:25 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:00:14 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

// Test 430 (p_void_width_fit) : FAILED.
//     First line of code: {return test("%5.p", NULL);}
//       expected return value : 5
//       your return value     : 2
//       expected output : "   0x"
//       your output     : "0x"
//       expected (nonprintable as hex) : "   0x"
//       actual   (nonprintable as hex) : "0x"

// Test 432 (p_ftfc_literal_9w_prec2_undefbehav) : FAILED.
//     First line of code: {return test("%9.2p
// ", 1234);}
//       expected return value : 11
//       your return value     : 6
//       expected output : "    0x4d2"
//       your output     : "0x4d2
// "
//       expected (nonprintable as hex) : "    0x4d2\x0a"
//       actual   (nonprintable as hex) : "0x4d2\x0a"


int main()
{
	// printf("!!%\n");
	// printf("\nSTART-----\n");
	// ft_printf("%");
	ft_printf("@#");
	printf("\nSTART-----\n");

	ft_printf("%05");
	printf("\nSTART-----\n");

	ft_printf("%5");
	printf("\nSTART-----\n");

	ft_printf("%-5");


	
	// printf("%5c\n", 'A');
	// printf("%05c\n", 'A');
	// printf("%-5c\n", 'A');
	// printf("%-05c\n", 'A');
	// printf("%.10d\n", -44);
	// printf("%10.5d\n",-44);
	// printf("%.10d\n", 44);
	// printf("%-10.5d#\n",44);
	return (0);
}

	// printf("%-9d", 99);
//000000099% 
	// printf("%-9d", 99);
//99       %   

// printf("%.d", 7); 정밀도로 될까 서식지정자가 될까
//7

