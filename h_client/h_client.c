/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:20:47 by wdebs             #+#    #+#             */
/*   Updated: 2017/02/16 23:26:22 by wdebs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/svrclnt.h"

int		main(void)
{
	int					sockfd;
	struct sockaddr_in	dest;
	char				buffer[MAXBUF];

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket error");
		exit(1);
	}
	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(MY_PORT);
	if (inet_aton(SERVER_ADDR, (struct in_addr *)&dest.sin_addr.s_addr) == 0)
	{
		perror(SERVER_ADDR);
		exit(1);
	}
	if (connect(sockfd, (struct sockaddr *)&dest, sizeof(dest)) != 0)
	{
		perror("Connection error");
		exit(1);
	}
	bzero(buffer, MAXBUF);
	while (1)
	{
		scanf("%s", buffer);
		if (strcmp(buffer, "exit") == 0)
			break ;
		send(sockfd, buffer, strlen(buffer), 0);
		memset(&buffer, 0, MAXBUF);
		recv(sockfd, buffer, MAXBUF, 0);
		write(1, &buffer, strlen(buffer));
		memset(&buffer, 0, MAXBUF);
	}
	close(sockfd);
	return  (0);
}
