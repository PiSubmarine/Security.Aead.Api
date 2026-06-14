# Security.Aead.Api

`PiSubmarine.Security.Aead.Api` defines the minimal contract for authenticated
encryption with associated data.

## Responsibility

This module owns:

- byte-oriented value types for keys, nonces, associated data, plaintext, and ciphertext
- the generic AEAD interface used by transport-facing code
- domain-specific error codes for invalid inputs and authentication failures

It does not own:

- nonce allocation strategy
- key management
- lease semantics
- datagram framing
- OpenSSL or any other concrete crypto backend
