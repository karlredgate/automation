package com.redgates.service;

import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.ext.ContextResolver;
import javax.ws.rs.ext.Provider;

import org.springframework.stereotype.Component;

import com.redgates.provider.JacksonObjectMapperFactory;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * Customize JSON handling.
 */
@Component
@Provider
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class ExampleProvider
implements ContextResolver<ObjectMapper> {
  private static final ObjectMapper objectMapper = JacksonObjectMapperFactory.getInstance();

  @Override
  public ObjectMapper getContext(final Class<?> type) {
    return objectMapper;
  }
}
