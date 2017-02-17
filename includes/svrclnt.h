/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   svrclnt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:21:52 by wdebs             #+#    #+#             */
/*   Updated: 2017/02/16 22:47:45 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SVRCLNT_H
# define SVRCLNT_H

# include <stdio.h>
# include <string.h>
# include <resolv.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <unistd.h>

# define MY_PORT		50234
# define SERVER_ADDR	"127.0.0.1"
# define MAXBUF			1024

#endif
