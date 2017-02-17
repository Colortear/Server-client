/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:20:55 by wdebs             #+#    #+#             */
/*   Updated: 2017/02/17 00:07:45 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/svrclnt.h"

int		main(void)
{
	int					sockfd;
	struct sockaddr_in	self;
	char				buffer[MAXBUF];
	int					clientfd;
	struct sockaddr_in	client_addr;
	unsigned int		addrlen;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		write(2, "socket error\n", 13);
		exit(1);
	}
	bzero(&self, sizeof(self));
	self.sin_family = AF_INET;
	self.sin_port = htons(MY_PORT);
	self.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&self, sizeof(self)) != 0)
	{
		write(2, "bind error\n", 11);
		exit(1);
	}
	if (listen(sockfd, 256) != 0)
	{
		write(2, "listen error\n", 13);
		exit(1);
	}
	while (1) {
		addrlen = sizeof(client_addr);
		clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
		printf("%s:%d connected\n", inet_ntoa(client_addr.sin_addr),
				ntohs(client_addr.sin_port));
		while (1) {
			if (recv(clientfd, buffer, MAXBUF, 0) > 0) {
				if (strcmp(buffer, "ping") == 0) {
					memset(&buffer[0], 0, sizeof(buffer));
					write(clientfd, "pong\npong\n", 10);
				}
				else {
					memset(&buffer[0], 0, sizeof(buffer));
					write(clientfd, "unusable input\n", 15);
				}
			}
			else {
				write(1, "Client has disconnected.\n", 25);
				break ;
			}
		}
		close(clientfd);
	}
	close(sockfd);
	return (0);
}
