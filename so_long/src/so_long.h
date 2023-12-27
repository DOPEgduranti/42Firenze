/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:22:12 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/19 10:24:16 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ftprintf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <time.h>

# define IMG_SIZE 64

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	ENEMY = 'N'
}	t_tiletype;

typedef struct s_wall_img
{
	void	*block;
	void	*gen;
	void	*corner1;
	void	*corner2;
}	t_wall_img;

typedef struct s_coll_img
{
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_coll_img;

typedef struct s_exit_img
{
	int			anim_frames;
	void		*img_0;
	void		*img_1;
	void		*img_2;
	t_vector	tile;
}	t_exit_img;

typedef struct s_effect
{
	void		*img;
	void		*death;
	t_vector	*pos;
	int			frames;
}	t_effect;

typedef enum e_enemytype
{
	HORIZONTAL_ENEMY = 'H',
	VERTICAL_ENEMY = 'V',
	FOLLOW_ENEMY = 'F',
	RANDOM_ENEMY = 'R'
}	t_enemytype;

typedef struct s_enemy_img
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;
	int		follow_anim;
	void	*follow_current;
	void	*follow_01;
	void	*follow_02;
}	t_enemy_img;

typedef struct s_enemy
{
	t_enemytype		type;
	int				dir;
	t_vector		*og_tile;
	t_vector		tile;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_player
{
	t_vector	tile;
	int			frame_count;
	int			idle_frames;
	void		*idle_img_0;
	void		*idle_img_1;
	int			action_frames;
	void		*action_img_0;
	void		*onexit_img;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	char			*mapname;
	char			**map;
	t_vector		map_size;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	char			*moves_str;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_img;
	t_coll_img		collects_img;
	t_enemy_img		enemy_imgs;
	t_exit_img		exit_img;
	void			*grass_img;
	t_effect		effect;
}	t_game;

t_player	ft_playergen(t_game *game);
t_coll_img	ft_collectgen(t_game *game);
char		**ft_mapgen(t_game *game, char *mapname);
t_bool		ft_filerror(int fd);
t_bool		ft_mtxerror(char **mtx);
t_bool		ft_mapsizerror(char **map, int a, int b);
t_bool		ft_objerror(char **map, int door, int player, int collect);
t_vector	ft_findfirst(char **map, char c);
t_wall_img	ft_wallgen(t_game *game);
void		ft_gamestart(t_game *game);
void		ft_putwall(t_game *game, int x, int y, int id);
void		ft_mtxdel(char ***mtx);
void		ft_putplayer(t_game *game, int x, int y, int id);
void		ft_putgrass(t_game *game, int x, int y, int id);
void		ft_putcoll(t_game *game, int x, int y, int id);
t_exit_img	ft_exitgen(t_game *game);
void		ft_putexit(t_game *game, int x, int y, int id);
void		ft_moveplayer(t_game *game, int keysym);
void		ft_pmove(t_game *game, int keysym);
t_bool		ft_getcoll(t_game *game, int keysym);
void		ft_win(t_game *game);
void		ft_closegame(t_game *game);
t_bool		ft_collectall(t_game *game);
t_vector	ft_keymove(int keysym);
t_vector	ft_mapsize(char **map);
t_bool		ft_isrectang(char **map);
t_bool		ft_checkwalls(char **map);
t_bool		ft_checkother(char **map);
t_enemy_img	ft_enemyimgset(t_game *game);
void		ft_putenemy(t_game *game, int x, int y, int id);
t_enemy		*ft_enemygen(t_game *game);
void		ft_enemyclear(t_enemy **lst);
t_enemy		*ft_enemynew(t_vector tile, t_enemytype type);
void		ft_enemyadd_back(t_enemy **lst, t_enemy *newe);
void		ft_enemymove(t_game *game, t_enemy *enemy);
void		ft_enemystartmove(t_game *game);
t_vector	ft_randommove(void);
void		ft_playeronexit(t_game *game, t_bool canfinish);
void		ft_printmoves(t_game *game);
void		ft_destroyplayer(t_game *game);
void		ft_destroyenemy(t_game *game);
void		ft_destroycollect(t_game *game);
void		ft_destroywall(t_game *game);
char		*ft_strjoin2(char *sta_str, char *buff);
t_game		ft_gameinit(char *mapname);
int			ft_key_hook(int keysym, t_game *game);
int			ft_exitbutton(t_game *game);
void		ft_savescore(t_game *game);
void		ft_death(t_game *game);

#endif