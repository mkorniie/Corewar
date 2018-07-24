/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:43 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:34:45 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include "../libft/libft.h"

int			g_n_of_f;
static char	*g_convs[] = {
	"schar*", "Swchar_t*", "pvoid*", "dint",
	"Dlong", "iint", "ounsigned int", "Ounsigned long",
	"uunsigned int", "Uunsigned long", "xunsigned int", "Xunsigned int",
	"cchar", "Cwint_t", "edouble", "Edouble",
	"fdouble", "Fdouble", "gdouble", "Gdouble",
	"adouble", "Adouble", "nint*", NULL
};
int			g_error;
int			**g_unistrings;
int			g_curr;
void		ft_addustring(void);
void		ft_freetwo(void *s1, void *s2);
int			ft_freestrarrs(char **split1, char **split2);
int			ft_changewidth(int *flg, char	*res, char x);
int			ft_printf(const char *restrict format, ...);
int			ft_parce(const char *restrict s, char *c, char ***flags);
int			ft_isspecifier(char x);
int			ft_modifpart1(int mod, int cvs);
int			ft_modifpart2(int mod, int cvs);
int			ft_ismod(char *flag);
int			ft_arrlen(char **arr);
int			ft_isvalid(char x);
int			ft_isflag(char *flag, char x);
int			ft_isflag(char *flag, char x);
uintmax_t	ft_powl(long num, long deg);
void		ft_freestrarr(char **split);
void		ft_freeintarr(int **split, int len);
int			*ft_widthpres(char *flag, int zeroflag);
int			*ft_findflag(char *flag);
char		*ft_validflag(char *temp);
char		*ft_chartostr(char c);
char		*ft_ubase(uintmax_t src, uintmax_t len, const char *pattern);
char		*ft_unicode(unsigned int src, int flag);
char		*ft_litoa(long n);
char		*ft_ulitoa(unsigned long n);
char		*ft_malloccharpzero(int len);
int			*ft_mallocintpzero(int len);
char		*ft_strdupfree(char *s1);
char		*ft_strdupfreearg(char *s1, char *free);
char		*ft_strndupfree(const char *s1, size_t n);
char		*ft_strjoinfree(char const *s1, char const *s2, int s_to_delete);
char		*ft_presicion(char *res, int pres, char x);
char		**ft_convert(va_list ap, char **flags);
char		**ft_fieldflags(char **res, char **flags);
char		*ft_scnv(va_list	ap);
char		*ft_sccnv(va_list	ap);
char		*ft_pcnv(va_list	ap);
char		*ft_dcnv(va_list	ap);
char		*ft_dccnv(va_list	ap);
char		*ft_icnv(va_list	ap);
char		*ft_ocnv(va_list	ap);
char		*ft_occnv(va_list	ap);
char		*ft_ucnv(va_list	ap);
char		*ft_uccnv(va_list	ap);
char		*ft_xcnv(va_list	ap);
char		*ft_xccnv(va_list	ap);
char		*ft_ccnv(va_list	ap);
char		*ft_cccnv(va_list	ap);
char		*ft_ecnv(va_list	ap);
char		*ft_eccnv(va_list	ap);
char		*ft_fcnv(va_list	ap);
char		*ft_fccnv(va_list	ap);
char		*ft_gcnv(va_list	ap);
char		*ft_gccnv(va_list	ap);
char		*ft_acnv(va_list	ap);
char		*ft_accnv(va_list	ap);
char		*ft_ncnv(va_list	ap);
char		*ft_hhocnv(va_list	ap);
char		*ft_hhucnv(va_list	ap);
char		*ft_hhxcnv(va_list	ap);
char		*ft_hhxccnv(va_list	ap);
char		*ft_hdcnv(va_list	ap);
char		*ft_hocnv(va_list	ap);
char		*ft_hucnv(va_list	ap);
char		*ft_hxcnv(va_list	ap);
char		*ft_hxccnv(va_list	ap);
char		*ft_lxcnv(va_list	ap);
char		*ft_lxccnv(va_list	ap);
char		*ft_dintmax_tcnv(va_list	ap);
char		*ft_ouintmax_tcnv(va_list	ap);
char		*ft_uuintmax_tcnv(va_list	ap);
char		*ft_xuintmax_tcnv(va_list	ap);
char		*ft_xcuintmax_tcnv(va_list	ap);
char		*ft_dssize_tcnv(va_list	ap);
char		*ft_osize_tcnv(va_list	ap);
char		*ft_usize_tcnv(va_list	ap);
char		*ft_xsize_tcnv(va_list	ap);
char		*ft_xcsize_tcnv(va_list	ap);
char		*ft_hhdcnv(va_list	ap);

static char	*(*g_ft_cvs[])(va_list	ap) = {
	&ft_scnv, &ft_sccnv, &ft_pcnv, &ft_dcnv,
	&ft_dccnv, &ft_icnv, &ft_ocnv, &ft_occnv,
	&ft_ucnv, &ft_uccnv, &ft_xcnv, &ft_xccnv,
	&ft_ccnv, &ft_cccnv, &ft_ecnv, &ft_eccnv,
	&ft_fcnv, &ft_fccnv, &ft_gcnv, &ft_gccnv,
	&ft_acnv, &ft_accnv, &ft_ncnv, &ft_hhocnv,
	&ft_hhucnv, &ft_hhxcnv, &ft_hhxccnv, &ft_hdcnv,
	&ft_hocnv, &ft_hucnv, &ft_hxcnv, &ft_hxccnv,
	&ft_lxcnv, &ft_lxccnv, &ft_dintmax_tcnv, &ft_ouintmax_tcnv,
	&ft_uuintmax_tcnv, &ft_xuintmax_tcnv, &ft_xcuintmax_tcnv, &ft_dssize_tcnv,
	&ft_osize_tcnv, &ft_usize_tcnv, &ft_xsize_tcnv, &ft_xcsize_tcnv,
	&ft_hhdcnv, NULL
};
char		*ft_zero(char	*res, int wp[2], char x);
char		*ft_hash(char	*res, int wp[2], char x);
char		*ft_leftadj(char	*res, int wp[2], char x);
char		*ft_space(char	*res, int wp[2], char x);
char		*ft_plus(char	*res, int wp[2], char x);
int			ft_printf(const char *restrict format, ...);
static char	*(*g_ft_flags[])(char	*res, int wp[2], char x) = {
	&ft_zero, &ft_hash, &ft_space, &ft_plus,
	&ft_leftadj, NULL
};
#endif
