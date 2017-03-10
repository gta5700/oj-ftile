
-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION oj_ftile" to load this file. \quit

CREATE OR REPLACE FUNCTION ftile(int4) RETURNS bigint AS
'$libdir/oj_ftile', 'ftile'
LANGUAGE 'c' WINDOW;

