#include "common.h"

SSL* WrapSocketWithSSL(int sock)
{
  SSL *ssl; SSL_CTX *ctx;

  /*
  openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout aeyxa.pem -out aeyxa.pem

  This is the command to generate the pem files.
  */

  SSL_library_init();
  std::cout << "1" << std::endl;
  ctx = InitServerCTX();
  std::cout << "2" << std::endl;
  LoadCertificates(ctx,"aeyxa.pem","aeyxa.pem");
  std::cout << "3" << std::endl;
  ssl = SSL_new(ctx);
  std::cout << "4" << std::endl;
  SSL_set_fd(ssl,sock);
  std::cout << "5" << std::endl;
  return ssl;
}

SSL_CTX* InitServerCTX(void)
{
  const SSL_METHOD *method; SSL_CTX *ctx;

  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();
  method = TLSv1_2_server_method();
  ctx = SSL_CTX_new(method);

  if(ctx == NULL)
  {
    ERR_print_errors_fp(stderr); abort();
  }
  return ctx;
}

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile)
{
  if(SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0)
  {
    ERR_print_errors_fp(stderr); abort();
  }
  if(SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0)
  {
    ERR_print_errors_fp(stderr); abort();
  }
  if(!SSL_CTX_check_private_key(ctx))
  {
    fprintf(stderr, "Private key does not match\n"); abort();
  }
}
