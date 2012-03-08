/*
** vm_funcs.h for corewar in /home/ecormi_p//crw-vm-asm/vm/vm_funcs
** 
** Made by pierre ecormier
** Login   <ecormi_p@epitech.net>
** 
** Started on  Tue Feb 21 15:31:47 2012 pierre ecormier
** Last update Thu Mar  8 16:54:32 2012 pierre ecormier
*/

#ifndef	__VM_FUNCS_H__
#define	__VM_FUNCS_H__

void		live(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		ld(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		st(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		add(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		sub(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		and(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		or(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		xor(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		zjmp(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		ldi(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		sti(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		fork(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		lld(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		lldi(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		lfork(t_arena *arena, t_champ *champ, char type[4], int argv[4]);
void		aff(t_arena *arena, t_champ *champ, char type[4], int argv[4]);

#endif
