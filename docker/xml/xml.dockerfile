FROM nginx:stable-alpine-slim

ENV RTS_DOMAIN=rts.unixcode.net

COPY cabin /usr/share/nginx/html/cabin
COPY conf/*.conf /etc/nginx/conf.d/
