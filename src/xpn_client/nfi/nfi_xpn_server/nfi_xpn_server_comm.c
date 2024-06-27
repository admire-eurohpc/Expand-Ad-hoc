
/*
 *  Copyright 2020-2024 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Dario Muñoz Muñoz
 *
 *  This file is part of Expand.
 *
 *  Expand is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Expand is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Expand.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


/* ... Include / Inclusion ........................................... */

#include "nfi_xpn_server_comm.h"

#ifdef ENABLE_MPI_SERVER
#include "nfi_mpi_server_comm.h"
#endif

/* ... Const / Const ................................................. */


/* ... Global variables / Variables globales ........................ */


/* ... Functions / Funciones ......................................... */

int nfi_xpn_server_comm_init ( struct nfi_xpn_server *params )
{
  int ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_init( params->xpn_thread );
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_init] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

int nfi_xpn_server_comm_destroy ( struct nfi_xpn_server *params )
{
  int ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_destroy( );
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_destroy] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

int nfi_xpn_server_comm_connect ( struct nfi_xpn_server *params )
{
  int ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_connect(params->srv_name, params->port_name, &params->server_comm);
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_connect] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

int nfi_xpn_server_comm_disconnect ( struct nfi_xpn_server *params )
{
  int ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_disconnect(&(params->server_comm));
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_disconnect] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

int nfi_xpn_server_comm_write_operation ( struct nfi_xpn_server *params, int op)
{
  int ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_write_operation(params->server_comm, op);
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_write_operation] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

ssize_t nfi_xpn_server_comm_write_data ( struct nfi_xpn_server *params, char *data, ssize_t size )
{
  ssize_t ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_write_data(params->server_comm, data, size);
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_write_data] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}

ssize_t nfi_xpn_server_comm_read_data ( struct nfi_xpn_server *params, char *data, ssize_t size )
{
  ssize_t ret = -1;

  switch (params->server_type)
  {
  #ifdef ENABLE_MPI_SERVER
  case XPN_SERVER_TYPE_MPI:
    ret = nfi_mpi_server_comm_read_data(params->server_comm, data, size);
    break;
  #endif
  
  default:
    printf("[NFI_XPN_SERVER] [nfi_xpn_server_comm_read_data] server_type '%d' not recognized\n",params->server_type);
    break;
  }

  return ret;
}


/* ................................................................... */
